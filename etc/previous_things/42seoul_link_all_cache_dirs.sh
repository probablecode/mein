# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    42seoul_link_all_cache_dirs.sh                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 15:50:44 by jaeskim           #+#    #+#              #
#    Updated: 2022/05/11 16:59:52 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#/bin/bash

BANNER="$(
  cat <<-EOF

EOF
)"

TARGET=(
  "Caches"
  "ApplicationSupport/Code/Cache"
  "ApplicationSupport/Code/CachedData"
  "ApplicationSupport/Code/CachedExtensions"
  "ApplicationSupport/Code/CachedExtensionVSIXs"
  "ApplicationSupport/Code/Code Cache"
  "ApplicationSupport/Slack/Cache"
  "ApplicationSupport/Slack/CachedData"
  "ApplicationSupport/Slack/Service Worker/CacheStorage"
  "ApplicationSupport/Slack/Service Worker/ScriptCache"
)

FLAG="$HOME/goinfre/issetup"

function link_all_cache_dirs() {
  echo "link Code Slack Cache dirs..."
  for ((i = 0; i < ${#TARGET[@]}; i++)); do
    mkdir -p "$HOME/goinfre/${TARGET[$i]}"
    rm -rf "$HOME/Library/${TARGET[$i]}"
    ln -s "$HOME/goinfre/${TARGET[$i]}" "$HOME/Library/${TARGET[$i]}"
  done
  echo "Complete link all Cache dirs!"
  touch "$FLAG"
}

if [ ! -e "$FLAG" ]; then
  echo "$BANNER"
  link_all_cache_dirs
fi
