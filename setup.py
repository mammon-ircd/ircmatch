from distutils.core import setup, Extension

setup (
    name='ircmatch',
    version='1.0',
    ext_modules=[Extension('ircmatch', ['ircmatch.c', 'ircmatch_python.c'])],
)

