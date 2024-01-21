# Instructions
## Installing Java
Ensure that homebrew is installed and then use it to install the `java` and `javac` tools:
```
brew install java
```

Make sure to follow the post-install symlink instructions so that `java` and `javac` are in the path:
```
For the system Java wrappers to find this JDK, symlink it with
  sudo ln -sfn /opt/homebrew/opt/openjdk/libexec/openjdk.jdk /Library/Java/JavaVirtualMachines/openjdk.jdk
```

## Running Template
```
javac MergeSort.java
java MergeSort
```
