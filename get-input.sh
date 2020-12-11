#!/bin/bash
# Fetches the input files from Advent of Code

day=${1}
session=${AOC_SESSION}
year="2020"
url="https://adventofcode.com/${year}/day/${day}/input"
output="day${day}/input.txt"

if [ -z "$session" ] ;
then
    echo "--> Missing AOC_SESSION environment variable";
    exit 1;
fi

echo "--> Fetching input for day ${day} from : ${url}"

curl -s -H "cookie: session=${session}" $url | tee $output

echo "--> Saved input to day ${day} to ${output}"
echo "--> All done."