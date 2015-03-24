from distutils.core import setup, Extension

setup (
    name='ircmatch',
    version='1.2',
    ext_modules=[Extension('ircmatch', ['ircmatch.c', 'ircmatch_python.c'])],
    description='library for matching IRC masks based on atheme',
    author='William Pitcock',
    author_email='nenolod@dereferenced.org',
    url='http://kaniini.dereferenced.org/projects/ircmatch.html'
)

