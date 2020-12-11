#!/bin/bash

day=${1}

cp -r _template day${day}

./get-input ${day}