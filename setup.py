#!/usr/bin/env python

from distutils.core import setup, Extension

with open('README.rst') as readme:
    long_description = readme.read()

setup (
    name='ircmatch',
    version='1.2',
    description='library for matching IRC masks based on atheme',
    long_description=long_description,
    author='William Pitcock',
    author_email='nenolod@dereferenced.org',
    url='http://kaniini.dereferenced.org/projects/ircmatch.html',
    ext_modules=[Extension('ircmatch', ['ircmatch.c', 'ircmatch_python.c'])],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Natural Language :: English',
        'License :: OSI Approved :: ISC License (ISCL)',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 3',
        'Topic :: Communications :: Chat',
    ],
)
