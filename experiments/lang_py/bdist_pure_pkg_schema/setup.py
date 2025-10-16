#!/usr/bin/env python

# The setup script is the centre of all activity in building, distributing,
# and installing modules using the Distutils. The main purpose of the setup
# script is to describe your first_module distribution to the Distutils, so that
# the various commands that operate on your modules do the right thing.
#
# Note that any pathnames (files or directories) supplied in the setup script
# should be written using the Unix convention, i.e. slash-separated.
# The Distutils will take care of converting this platform-neutral
# representation into whatever is appropriate on your current platform before
# actually using the pathname. This makes your setup script portable across
# operating systems, which of course is one of the major goals of the Distutils.

from distutils.core import setup

# In particular, setuptools is an enhanced alternative to distutils that
#provides:
# - support for declaring project dependencies
# - additional mechanisms for configuring which files to include in source
# releases (including plugins for integration with version control systems)
# - the ability to declare project "entry points", which can be used as the
# basis for application plugin systems
# - the ability to automatically generate Windows command line executables
# at installation time rather than needing to prebuild them
# - consistent behaviour across all supported Python versions
# The recommended pip installer runs all setup.py scripts with setuptools,
# even if the script itself only imports distutils.

setup(name='bdist_pure_pkg_sample',
      version='1.0.0',
      author='Karol Zmijewski',
      author_email='karol.zmijewski@gmail.com',
      maintainer='Karol Zmijewski',
      maintainer_email='karol.zmijewski@gmail.com',
      url='http://karolzmijewski.myqnapcloud.com:9000',
      download_url='http://karolzmijewski.myqnapcloud.com:9000',
      description='Python package sample.',
      long_description='Python package sample using distribution utilities.',
      classifiers=['Programming Language :: Python :: 3',
                   'Intended Audience :: Education',
                   'Operating System :: OS Independent',
                   'Development Status :: 4 - Beta',
                   'Environment :: Console'],
      platforms=['x86', 'x64'],
      keywords=['samples', 'bdist', 'patterns', 'package'],
      packages=['bdist_pure_pkg_sample',
                'bdist_pure_pkg_sample.first_module',
                'bdist_pure_pkg_sample.second_module'],
      package_dir={'bdist_pure_pkg_sample': 'src'},
      package_data={'bdist_pure_pkg_sample': ['first_module/*.json',
                                              'first_module/*.txt']}
)