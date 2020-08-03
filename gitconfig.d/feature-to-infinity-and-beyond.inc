[alias]

  feature-to-infinity-and-beyond = "!f() { \
    : git checkout ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'usage: git feature-to-infinity-and-beyond <feature name>...'; \
    else \
      feature_name=$(if echo "${1}"|grep -q 'feature/'; then echo "${*}"|tr ' ' '-'; else echo feature/"${*}"|tr ' ' '-'; fi); \
      [ -n "${feature_name}" ] || { echo "feature_name was NOT found, exiting..."; exit 1; }; \
      echo; \
      echo '-- feature-end --'; \
      echo; \
      git fetch origin --prune && \
      git push --set-upstream origin "${feature_name}"; \
      echo; \
      echo '-- feature-to-next --'; \
      echo; \
      git fetch origin --prune && \
      git checkout next && \
      git reset --hard origin/next && \
      git merge --message 'Merge branch '"${feature_name}"' into next' --no-ff "${feature_name}"; \
      echo; \
      echo '-- publish-next --'; \
      echo; \
      git fetch origin --prune && \
      git push --set-upstream origin next; \
      echo; \
      echo '-- feature-to-master --'; \
      echo; \
      git fetch origin --prune && \
      git checkout master && \
      git reset --hard origin/master && \
      git merge --message 'Merge branch '"${feature_name}"' into master' --no-ff "${feature_name}"; \
      echo; \
      echo '-- publish-master --'; \
      echo; \
      git fetch origin --prune && \
      git push --set-upstream origin master; \
      echo; \
      echo '-- feature-clean --'; \
      echo; \
      git branch --list 'feature/*' --merged|xargs git branch --delete 2> /dev/null && \
      git gc --auto --quiet; \
    fi; \
    }; f"
