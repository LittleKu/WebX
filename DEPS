deps = {
  'src' : 'https://github.com/LittleKu/base@ca2f5975eb047022d3a6d38ec07e187f9c49cc56',
}

hooks = [
  {
    'name': 'download_and_extract_cef',
    'pattern': '.',
    'action': [
      'python3',
      'src/webx/tools/download_and_extract_libcef.py',
      '--url=https://cef-builds.spotifycdn.com/cef_binary_132.3.1%2Bg144febe%2Bchromium-132.0.6834.83_windows64.tar.bz2',
      '--bz2_file=src/webx/cef_binary_132.3.1+g144febe+chromium-132.0.6834.83_windows64.tar.bz2',
      '--dest_dir=src/webx/libcef',
    ],
  },
]

recursedeps = [
  'src',
]