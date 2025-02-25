import os
import sys
import tarfile
import optparse
import urllib.request

def download_progress_hook(count, block_size, total_size):
  downloaded = count * block_size
  percent = downloaded / total_size * 100 if total_size > 0 else 0

  bar_length = 40
  filled_length = int(bar_length * percent / 100)
  bar = '-' * filled_length + ' ' * (bar_length - filled_length)
  if total_size > 0:
    status = f"{percent:.1f}% [{bar}] {downloaded/1024/1024:.1f}MB / {total_size/1024/1024:.1f}MB"
  else:
    status = f"{downloaded/1024/1024:.1f}MB Unkown total size"
  print(f"\r{status}", end='',flush=True)

def extract_filter(tarinfo):
  print("filename:{tarinfo.name}")
  return tarinfo

def main(args):
  parser = optparse.OptionParser('usage: %prog --bz2_file=<bz2_file> --dest_dir=<dest_dir>')
  parser.add_option('', '--url', dest='url', help='url to download libcef')
  parser.add_option('', '--bz2_file', dest='bz2_file', help='bz2 file to extract')
  parser.add_option('', '--dest_dir', dest='dest_dir', help='destination directory')
  options, _ = parser.parse_args(args)
  if not options.bz2_file or not options.dest_dir or not options.url:
    parser.print_help()
    sys.exit(1)

  if not os.path.exists(options.dest_dir):
    os.makedirs(options.dest_dir)

  urllib.request.urlretrieve(options.url, options.bz2_file, download_progress_hook)
  tar = tarfile.open(options.bz2_file, 'r:bz2')
  tar.extractall(options.dest_dir)

if __name__ == '__main__':
  try:
    sys.exit(main(sys.argv[1:]))
  except Exception as e:
    sys.stderr.write(str(e) + '\n')
    sys.exit(1)