import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="mhar",
    version="0.0.2",
    author="Mario Vazquez Corte uumami",
    author_email="uumami@sonder.art",
    description="The MHAR package for polytopes, in pytorch",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/uumami/mhar",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
)

install_requires = [
    'elasticsearch>=1.6'
]