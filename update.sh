#!/bin/sh

nbdev_export
pip install -e '.[dev]'
nbdev_test