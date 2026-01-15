from setuptools import find_packages
from setuptools import setup

setup(
    name='center_msg_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('center_msg_pkg', 'center_msg_pkg.*')),
)
