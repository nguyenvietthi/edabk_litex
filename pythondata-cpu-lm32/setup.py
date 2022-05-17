import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

from pythondata_cpu_lm32 import version_str

setuptools.setup(
    name="pythondata-cpu-lm32",
    version=version_str,
    author="LiteX Authors",
    author_email="litex@googlegroups.com",
    description="""\
Python module containing verilog files for LatticeMico32 cpu.""",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/litex-hub/pythondata-cpu-lm32",
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: Eclipse Public License 1.0 (EPL-1.0)",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.5',
    zip_safe=False,
    packages=setuptools.find_packages(),
    package_data={
    	'cpu_lm32': ['cpu_lm32/verilog/**'],
    },
    include_package_data=True,
    project_urls={
        "Bug Tracker": "https://github.com/litex-hub/pythondata-cpu-lm32/issues",
        "Source Code": "https://github.com/litex-hub/pythondata-cpu-lm32",
    },
)
