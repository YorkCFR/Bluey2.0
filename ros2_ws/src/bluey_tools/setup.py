from setuptools import setup
import os
from glob import glob

package_name = 'bluey_tools'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('icons/*')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jenkin',
    maintainer_email='jenkin@yorku.ca',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'bluey_ctrl = bluey_tools.bluey_ctrl_node:main',
            'bluey_video = bluey_tools.bluey_video_node:main',
            'bluey_ui = bluey_tools.bluey_ui_node:main',
        ],
    },
)
