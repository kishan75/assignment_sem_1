#!/bin/bash

read -p 'url: ' url
read -p 'word to be count: ' word

content=`lynx -dump $url | grep -o -i $word | wc -l`

echo $content

