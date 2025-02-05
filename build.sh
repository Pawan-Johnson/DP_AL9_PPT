#!/bin/bash

# Build the project
latexmk -shell-escape -auxdir=build -outdir=build -interaction=nonstopmode -pdf main.tex