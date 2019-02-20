#ifndef UT_FS_H
#define UT_FS_H
#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/info_content_visitor.cpp"
#include "../src/find_link_visitor.cpp"
#include "../src/find_visitor.cpp"
#include "../src/find_node_by_pathname_visitor.cpp"
#include "../src/node_iterator.h"
#include "../src/link.h"
#include "../src/node_builder.h"
#include <memory>

class FileSystemTest: public ::testing::Test
{
protected:
  void SetUp() override
  {
    test_data = new Folder ("./test_data");
    folder = new Folder("./test_data/folder");
    hello_cpp = new File("./test_data/hello.cpp");
    a_out = new File("./test_data/folder/a.out");
    hello = new Link("./test_data/hello", a_out);
    folder->add(a_out);
    test_data->add(folder);
    test_data->add(hello);
    test_data->add(hello_cpp);
  }

  void TearDown() override
  {
    delete a_out;
    delete hello_cpp;
    delete hello;
    delete folder;
    delete test_data;
  }

  Node * test_data;
  Node * folder;
  Node * hello_cpp;
  Node * a_out;
  Node * hello;

};

TEST_F (FileSystemTest, Visitor)
{
  InfoContentVisitor * icv = new InfoContentVisitor();
  a_out->accept(icv);
  ASSERT_EQ(8432, icv->getContentSize());
  delete icv;

  InfoContentVisitor * icv10 = new InfoContentVisitor();
  hello->accept(icv10);
  ASSERT_EQ(8432,icv10->getContentSize());
  // icv = new InfoContentVisitor("");
  InfoContentVisitor * icv2 = new InfoContentVisitor();
  folder->accept(icv2);
  ASSERT_EQ(8432, icv2->getContentSize());

  InfoContentVisitor * icv3 = new InfoContentVisitor();
  test_data->accept(icv3);
  ASSERT_EQ(16864,icv3->getContentSize());

}
TEST_F (FileSystemTest,NodeIterator){
  std::unique_ptr<NodeIterator> it(test_data->createIterator());
  // NodeIterator * it = test_data->createIterator();
  it->first();
  // ASSERT_EQ(4096, it->currentItem()->size());
  it->next();
  ASSERT_EQ(12, it->currentItem()->size());
  it->next();
  ASSERT_EQ(0, it->currentItem()->size());
  it->next();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());

  // delete it;
}

TEST_F (FileSystemTest, FindLinkVisitor) {
    NodeBuilder nb;
    nb.build("./test_data");
    // NodeIterator *it = nb.getRoot()->createIterator();
    // for (it->first();!it->isDone();it->next())
    // {
    //   cout << it->currentItem()->path() << endl;
    // }
    FindLinkVisitor * icv = new FindLinkVisitor();
    test_data->accept(icv);
    ASSERT_EQ("hello",icv->getLinks()[0]->name());

}

TEST_F (FileSystemTest, FindVisitor) {
    NodeBuilder nb;
    nb.build("test_data");
    FindVisitor * icv = new FindVisitor("a.out");
    test_data->accept(icv);
    ASSERT_EQ("./folder/a.out",icv->findResult());

}

TEST_F (FileSystemTest, NodeTypeError)
{
  ASSERT_ANY_THROW(new File("./test_data/folder"));//Do not indicate the file path.
  ASSERT_ANY_THROW(new Folder("./test_data/hello"));//Do not indicate the Folder path.
  ASSERT_ANY_THROW(new Link("./test_data/hello.cpp"));//Do not indicate the Link path.
}

TEST (FindNodeByPathnameVisitor, Link){
      Node * hello = new Link("./test_data/hello");
      std::vector<std::string>* names = new std::vector<std::string>{std::string("hello")};
      FindNodeByPathnameVisitor *fv = new FindNodeByPathnameVisitor (names);
      hello->accept(fv);
      ASSERT_EQ(hello, fv->getNode());
}
TEST (FindNodeByPathnameVisitor, LinkInFolder){
      Node * test_data = new Folder ("./test_data");
      Node * hello = new Link("./test_data/hello");
      test_data->add(hello);
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("hello")};
      FindNodeByPathnameVisitor *fv = new FindNodeByPathnameVisitor (names);
      test_data->accept(fv);
      ASSERT_EQ(hello, fv->getNode());
}
TEST (FindNodeByPathnameVisitor, nonExistingFileInFileSystem){
      Node * test_data = new Folder ("./test_data");
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("helloWorld")};
      FindNodeByPathnameVisitor *fv = new FindNodeByPathnameVisitor (names);
      test_data->accept(fv);
      ASSERT_EQ(nullptr, fv->getNode());
}

TEST (FindNodeByPathnameVisitor, EmptyNames){
      Node * test_data = new Folder ("./test_data");
      std::vector<std::string>* names = new std::vector<std::string>{};
      FindNodeByPathnameVisitor *fv = new FindNodeByPathnameVisitor (names);
      test_data->accept(fv);
      ASSERT_EQ(nullptr, fv->getNode());
}


TEST (Test, GP) {
    
    NodeBuilder nb;
    nb.build("test_data");
    Node * test_data = nb.getRoot() ;
    NodeIterator *it = nb.getRoot()->createIterator();
    cout << nb.getRoot()->name() << endl ;
    for (it->first();!it->isDone();it->next())
    {
      cout << "第一層"<<  it->currentItem()->name() << endl;
        
    }
    
    FindLinkVisitor * icv = new FindLinkVisitor();
    test_data->accept(icv);
    ASSERT_EQ("hello",icv->getLinks()[0]->name());

}

#endif
