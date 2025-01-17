# simple-git-feature-branch-workflow

## About

This project provides a few git aliases to help with the [Git Feature Branch Workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/feature-branch-workflow).

From the Atlassian website:

> The core idea behind the Feature Branch Workflow is that all feature development should take place in a dedicated branch instead of the **master** branch. This encapsulation makes it easy for multiple developers to work on a particular feature without disturbing the main codebase. It also means the **master** branch will never contain broken code, which is a huge advantage for continuous integration environments.

## Prerequisites

These aliases should work in any *NIX based OS (Linux, macOS, WSL ?¿?) with git installed, anyway, the complete list of used commands is:

* awk
* cat
* cut
* echo
* git
* grep
* sed
* tr
* xargs

## Install

  1. Get this repo:

      ```text
      git clone https://github.com/jobace78/simple-git-feature-branch-workflow.git ~/.simple-git-feature-branch-workflow
      ```

  2. Update your configuration:

      Edit your `~/.gitconfig` file with something like this:

      ```text
      [include]
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/auto.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/auto-staged-only.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-abort.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-clean.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-continue.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-from-main.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-from-master.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-from-next.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-list.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-to-main.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-to-master.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-to-next.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/feature-where-is.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/publish-feature.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/publish-main.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/publish-master.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/publish-next.inc
        path = ~/.simple-git-feature-branch-workflow/gitconfig.d/release.inc
      ```

## Usage

We'll create a "sandbox" to play safe:

```shell
cd /tmp || exit 1 && \
git init --bare --initial-branch main test.git && \
git clone test.git test && \
cd test && \
git config commit.gpgsign false && \
git config user.email example@example.org && \
echo '# test' > README.md && \
git add README.md && \
git commit -m "Initial commit" && \
git push --set-upstream origin main && \
git remote set-head origin main
```

  1. *Begin* a new feature from **main** or **master**:

      ```shell
      git feature-from-main WIP-1
      ```

      ```shell
      git feature-from-master WIP-1
      ```

  2. Add something:

      ```shell
      echo 'test' > test.txt
      git add test.txt
      git auto-staged-only
      ```

  3. *Push* (A.K.A. publish) the local **feature** branch into **remote/origin**:

      ```shell
      git publish-feature WIP-1
      ```

  4. *Merge* (A.K.A. integrate) the feature in the local **main** or **master** branch:

      ```shell
      git feature-to-main WIP-1
      ```

      ```shell
      git feature-to-master WIP-1
      ```

  5. *Push* (A.K.A. publish) the local **main** or **master** branch into **remote/origin**:

      ```shell
      git publish-main
      ```

      ```shell
      git publish-master
      ```

  6. *Clean* the feature:

      ```shell
      git feature-clean
      ```

## Notes

  1. If you find any problem during the merge operation (git feature-to-next, git feature-to-main or git feature-to-master) you can abort at any time with `git feature-abort`.

  2. The merge operation (git feature-to-next, git feature-to-main or git feature-to-master) does not have a strict order (regarding other branches), but is advisable to merge the branch in a short space of time and **next** should be merged before **main** or **master**.

  3. You can check if a branch has been already merged with `git feature-where-is <feature branch name>`.

## Status

* auto : OK
* auto-staged-only : OK
* feature-abort : OK
* feature-clean : OK
* feature-continue : OK
* feature-from-main : OK
* feature-from-master : OK
* feature-from-next : OK
* feature-list : OK
* feature-to-main : OK
* feature-to-master : OK
* feature-to-next : OK
* feature-where-is : OK
* publish-feature : OK
* publish-main : OK
* publish-master : OK
* publish-next : OK
* release : OK

## License

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
