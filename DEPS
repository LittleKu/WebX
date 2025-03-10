gclient_gn_args_from = 'src'

vars = {
  'libcef_cdn_url': 'https://cef-builds.spotifycdn.com/',
  'libcef_package': 'cef_binary_131.4.1+g437feba+chromium-131.0.6778.265_windows64.tar.bz2',
  'libcef_sha1': '11dbbda8aac09da779d22406eb7042336b148724',
}

deps = {
  'src' : 'https://github.com/LittleKu/base@a5c8fdac2f1f0189d24e2d3920a182b8fdfc693a',
}

hooks = [
  {
    'name': 'download_and_extract_cef',
    'pattern': '.',
    'action': [
      'python3',
      'src/webx/tools/download_and_extract_libcef.py',
      '--url=' + Var('libcef_cdn_url') + Var('libcef_package'),
      '--sha1=' + Var('libcef_sha1'),
      '--bz2_file=src/webx/' + Var('libcef_package'),
      '--dest_dir=src/webx/libcef',
    ],
  },
]

recursedeps = [
  'src',
]