[alias]

  feature-end-current = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; echo exit 1; fi; done; \
    echo '-- THIS ALIAS IS IN BETA STATE --'; \
    echo; \
    feature_name=$(git branch --list '*'|grep '*'|cut -d ' ' -f 2); \
    repository_name=$(git remote get-url origin|tr ./:@ _ 2> /dev/null); \
    [ -n "${feature_name}" ] || { echo "feature_name was NOT found, exiting..."; exit 1; }; \
    [ -n "${repository_name}" ] || { echo "repository_name was NOT found, exiting..."; exit 1; }; \
    if [ "${feature_name}" = 'master' ] || [ "${feature_name}" = 'next' ]; then \
      echo "${feature_name} is forbidden..."; \
    else \
      echo "${feature_name}" > /tmp/"${repository_name}".txt; \
      git fetch origin --prune && \
      git push --set-upstream origin "${feature_name}"; \
    fi; \
    }; f"
