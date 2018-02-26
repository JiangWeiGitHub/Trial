#!/usr/bin/env bash

set -eu

DASH="------------------------------------------------------------"

banner_front()
{
  sleep 1s
  echo ""
  echo $DASH
  echo "$1"
  echo ""
}

banner_end()
{
  echo ""
  echo "$1"
  echo $DASH
  echo ""
  sleep 1s
}
