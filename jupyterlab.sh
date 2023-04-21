#!/bin/sh

# TODO: remove ""
conda run -n  base jupyter lab --ip=0.0.0.0 --allow-root --NotebookApp.token='' --NotebookApp.password=''
