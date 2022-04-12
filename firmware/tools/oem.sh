#!/bin/bash

while true
do
  echo "Uploading OEM test"
  pio run -e oemtest -t upload -d ..
  read -p "Press enter to upload default firmware"

  echo "Uploading default firmware"
  pio run -e bizcard_v4 -t upload -d ..
  read -p "Press enter to continue"
done