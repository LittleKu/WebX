import os
import shutil
import sys
import tarfile
import optparse
import urllib.request
import hashlib

def download_progress_hook(count, block_size, total_size):
  downloaded = count * block_size
  percent = downloaded / total_size * 100 if total_size > 0 else 0

  bar_length = 40
  filled_length = int(bar_length * percent / 100)
  bar = '=' * filled_length + '-' * (bar_length - filled_length)
  if total_size > 0:
    status = f"{percent:.1f}% [{bar}] {downloaded/1024/1024:.1f}MB / {total_size/1024/1024:.1f}MB"
  else:
    status = f"{downloaded/1024/1024:.1f}MB Unkown total size"
  print(f"\r{status}", end='',flush=True)

def extract_without_top_folder(tar_path, target_path):
  with tarfile.open(tar_path, 'r') as tar:
    members = tar.getmembers()

    first_level = {}
    for member in members:
      parts = member.name.split('/', 1)
      top_name = parts[0]

      if top_name not in first_level:
        first_level[top_name] = []
      first_level[top_name].append(member)

    if len(first_level) == 1:
      top_dir = next(iter(first_level.keys()))

      is_directory = any(
        m.name == top_dir or m.isdir()
        for m in members)

      all_inside = all(
        m.name == top_dir or
        m.name.startswith(top_dir + '/')
        for m in members
      )

      if is_directory and all_inside:
        for member in members:
          if member.name == top_dir:
            continue
          if member.name.startswith(top_dir + '/'):
            member.name = member.name[len(top_dir) + 1:]
          if not member.name.strip('/'):
            continue

        filtered_members = [
          m for m in members
          if m.name != top_dir and m.name.strip('/')
        ]

        tar.extractall(target_path, members=filtered_members)
        return

    tar.extractall(target_path)

def verify_sha1(file_path, expected_sha1):
  print(f"Verifying {file_path} sha1...")
  sha1 = hashlib.sha1()
  with open(file_path, 'rb') as f:
    for chunk in iter(lambda: f.read(4096), b''):
      sha1.update(chunk)
  calculated = sha1.hexdigest().lower()
  return calculated == expected_sha1.lower()

def main(args):
  parser = optparse.OptionParser('usage: %prog --bz2_file=<bz2_file> --dest_dir=<dest_dir>')
  parser.add_option('', '--url', dest='url', help='url to download libcef')
  parser.add_option('', '--sha1', dest='sha1', help='sha1 of the bz2 file')
  parser.add_option('', '--bz2_file', dest='bz2_file', help='bz2 file to extract')
  parser.add_option('', '--dest_dir', dest='dest_dir', help='destination directory')
  options, _ = parser.parse_args(args)
  if not options.bz2_file or not options.dest_dir or not options.url:
    parser.print_help()
    sys.exit(1)

  if os.path.exists(options.dest_dir):
    shutil.rmtree(options.dest_dir)

  os.makedirs(options.dest_dir)

  if os.path.exists(options.bz2_file) and os.path.isfile(options.bz2_file) and verify_sha1(options.bz2_file, options.sha1):
    print('File %s already exists and verify sha1 successed, skipping download...' % options.bz2_file)
  else:
    print('Downloading %s...' % options.bz2_file)
    urllib.request.urlretrieve(options.url, options.bz2_file, download_progress_hook)

  print('Extracting %s...' % options.bz2_file)
  extract_without_top_folder(options.bz2_file, options.dest_dir)

if __name__ == '__main__':
  try:
    sys.exit(main(sys.argv[1:]))
  except Exception as e:
    sys.stderr.write(str(e) + '\n')
    sys.exit(1)