[alias]

  feature-to-master-current = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; exit 1; fi; done; \
    echo '-- THIS ALIAS IS IN BETA STATE --'; \
    echo; \
    repository_name=$(git remote get-url origin|tr ./:@ _ 2> /dev/null); \
    [ -n "${repository_name}" ] || { echo "repository_name was NOT found, exiting..."; exit 1; }; \
    if [ -f /tmp/"${repository_name}".txt ]; then \
      feature_name=$(cat /tmp/"${repository_name}".txt); \
      [ -n "${feature_name}" ] || { echo "feature_name was NOT found, exiting..."; exit 1; }; \
      if [ "${feature_name}" = 'master' ] || [ "${feature_name}" = 'next' ]; then \
        echo "${feature_name} forbidden..."; \
      else \
        git fetch origin --prune && \
        git checkout master && \
        git merge --message 'Merge branch '"${feature_name}"' into master' --no-ff "${feature_name}"; \
      fi; \
    else \
      echo "/tmp/${repository_name}.txt was NOT found, nothing to do..."; \
    fi; \
    }; f"
