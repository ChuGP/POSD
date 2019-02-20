#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include <cstring>

class NodeBuilder {
public:
  NodeBuilder() {}


  void build(char * path) {
    // cout << path << endl ;
    struct stat st;
    if (lstat(path, &st) == 0) {
      if (S_ISREG(st.st_mode))
        _root = new File(path);
      else if (S_ISLNK(st.st_mode))
        _root = new Link(path);
      else if (S_ISDIR(st.st_mode)) {
        _root = new Folder(path);
        DIR * dir = opendir(path);
        if (dir == nullptr)
          throw std::string("open folder error");

        struct dirent * entry = nullptr;
        while((entry = readdir(dir)) != nullptr) {
          if (std::string(entry->d_name) != "."
              && std::string(entry->d_name) != "..") {
            // cout << string(entry->d_name)  << endl ;
            NodeBuilder nb ;
            char * pathName = new char[sizeof(path)+1+sizeof(entry->d_name)];
            strcpy(pathName,path);
            strcat(pathName,"/");
            strcat(pathName,entry->d_name);
            nb.build(pathName);
            _root->add(nb.getRoot());
          } // if
        } // while
      } // if
    } // if
  } // build

  Node * getRoot() {
    return _root;
  }

private:
  Node * _root;
};

#endif
