import os
from setuptools import find_packages
from setuptools import setup

setup(
    name='mbzirc_ign',
    version='0.0.0',
    packages=find_packages(
        include=('mbzirc_ign', 'mbzirc_ign.*')),
)
