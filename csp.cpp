#include <iostream>
#include <fstream>
#include <vector>

struct Relation {
  Relation(int m, int n, int M = 0) :
      min{m}, nominal{n}, max{M} {inf = M == 0;}
  Relation(int n) :
    Relation(n,n,n) {}
  int min;
  int nominal;
  bool inf;
  int max;
};

struct Node {
  Node(int d) : date{d} {}
  int date;
  std::vector<Relation*> nextTimeRelations;
};

std::vector<Node*> simple()
{
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5};
  auto n3 = new Node{8};
  
  n->nextTimeRelations.push_back(new Relation{2, 8, 10});  
  n1->nextTimeRelations.push_back(new Relation{7, 8, 15});
  n2->nextTimeRelations.push_back(new Relation{3});

  return {n, n1, n2, n3};
}

std::vector<Node*> minimal_rigid()
{
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5};
  
  n->nextTimeRelations.push_back(new Relation{2, 5, 10});  
  n1->nextTimeRelations.push_back(new Relation{7, 8, 15});

  return {n, n1, n2};
}

std::vector<Node*> test()
{
  auto n = new Node{0};
  auto n1 = new Node{5};
  auto n2 = new Node{8};
  auto n3 = new Node{17};
  
  n->nextTimeRelations.push_back(new Relation{6, 8, 10});
  n->nextTimeRelations.push_back(new Relation{3, 5, 6});
  
  n1->nextTimeRelations.push_back(new Relation{10, 12, 15});
  n2->nextTimeRelations.push_back(new Relation{8, 9, 12});

  return {n, n1, n2, n3};
}

// *********************************
std::vector<Node*> general()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5};
  auto n3 = new Node{8};
  auto n4 = new Node{15};
  auto n5 = new Node{22};
  
  n->nextTimeRelations.push_back(new Relation{2, n2->date - n->date, 10});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 12});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 13});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});
  n4->nextTimeRelations.push_back(new Relation{6, n5->date - n4->date, 9});

  return {n, n1, n3, n2, n4, n5};
}

std::vector<Node*> coherent()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5};
  auto n3 = new Node{8};
  auto n4 = new Node{15};
  
  n->nextTimeRelations.push_back(new Relation{4, n2->date - n->date, 9});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 15});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 12});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});

  return {n, n1, n3, n2, n4};
}

std::vector<Node*> coherent_min()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{4};
  auto n3 = new Node{6};
  auto n4 = new Node{12};
  
  n->nextTimeRelations.push_back(new Relation{4, n2->date - n->date, 9});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 15});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 12});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});

  return {n, n1, n3, n2, n4};
}
std::vector<Node*> coherent_max()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{9};
  auto n3 = new Node{12};
  auto n4 = new Node{21};
  
  n->nextTimeRelations.push_back(new Relation{4, n2->date - n->date, 9});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 15});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 12});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});
 
  return {n, n1, n3, n2, n4};
}

std::vector<Node*> coherent_exec1()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5}; // fixé
  auto n3 = new Node{7};
  auto n4 = new Node{14};
  
  n->nextTimeRelations.push_back(new Relation{4, n2->date - n->date, 9});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 15});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 12});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});

  return {n, n1, n3, n2, n4};
}

std::vector<Node*> coherent_exec_min()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5}; // fixé
  auto n3 = new Node{6}; // au min
  auto n4 = new Node{14};
  
  n->nextTimeRelations.push_back(new Relation{4, n2->date - n->date, 9});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 15});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 12});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});

  return {n, n1, n3, n2, n4};
}

std::vector<Node*> coherent_exec_max()
{
  //n n2 n4
  //n1 n3 n4
  auto n = new Node{0};
  auto n1 = new Node{-3};
  auto n2 = new Node{5}; // fixé
  auto n3 = new Node{12}; // au max
  auto n4 = new Node{18};
  
  n->nextTimeRelations.push_back(new Relation{4, n2->date - n->date, 9});  
  n1->nextTimeRelations.push_back(new Relation{9, n3->date - n1->date, 15});
  n2->nextTimeRelations.push_back(new Relation{8, n4->date - n2->date, 12});
  n3->nextTimeRelations.push_back(new Relation{6, n4->date - n3->date, 9});

  return {n, n1, n3, n2, n4};
}

std::vector<Node*> modif_passe()
{
  //n n1 n2
  //n3 n2
  auto n = new Node{0};
  auto n1 = new Node{7};
  auto n2 = new Node{12}; // fixé
  auto n3 = new Node{-3}; // au max
  
  n->nextTimeRelations.push_back(new Relation{4, n1->date - n->date, 11});  
  n1->nextTimeRelations.push_back(new Relation{n2->date - n1->date});
  n3->nextTimeRelations.push_back(new Relation{12, n2->date - n3->date, 19});

  return {n, n1, n3, n2};
}


int main(int argc, char *argv[])
{
  std::ofstream output;
  std::string name = "schema";
  if(argc == 2)
  {
    name = argv[1];
  }
  std::string filename = name + ".tex";
  output.open(filename);
  
  std::vector<Node*> timenodes = modif_passe();
  
  output << "\\def\\schemaScenario " << name << "{%\n";
  output << "\\begin{tikzpicture}[scale=0.3]%\n";
  
  int Tcounter = 0;
  int Ccounter = 1;
  int yPos = 0;
  std::string constraintName;
  std::string nodeName;
  int date;
  
  
  for(auto &node : timenodes)
  {
      date = (int) node->date;

      output << "\\def\\date{" << date << "};%\n";

      for(auto &constraint : node->nextTimeRelations)
      {
          constraintName = "C"+std::to_string(Ccounter);

          yPos = -2*Ccounter;

          output << "\\def\\contraintName{" << constraintName << "};%\n";
          output << "\\def\\ypos{" << yPos << "};%\n";
          output << "\\def\\min{" << constraint->min << "};%\n";
          output << "\\def\\nom{" << constraint->nominal << "};%\n";
          if(!constraint->inf)
          {output << "\\def\\max{" << constraint->max << "};%\n";}
          else
          {output << "\\def\\max{" << constraint->nominal+1 << "};%\n";}
          output << "\\fill (\\date,\\ypos) circle (0.3);%\n";
          output << "\\fill (\\date+\\nom,\\ypos) circle (0.3);%\n";
          output << "\\draw (\\date,\\ypos) -- ++(\\min,0) node[midway,above,scale=1] {\\contraintName};%\n";
          output << "\\draw (\\date+\\min,\\ypos+0.5) -- ++(0,-1);%\n";
          output << "\\draw[dotted] (\\date+\\min,\\ypos) -- (\\date+\\max,\\ypos);%\n";
          if(!constraint->inf)
          {output << "\\draw (\\date+\\max,\\ypos+0.5) -- ++(0,-1);%\n%\n";}
          Ccounter++;
      }

      nodeName = "\\Huge T"+std::to_string(Tcounter);

      output << "\\def\\nodeName{" << nodeName << "};%\n";
      output << "\\def\\ypos{" << (yPos -1) << "};%\n";
      output << "\\draw (\\date,0) -- ++(-1,0.5) -- ++(0,2) -- ++(2,0) -- ++(0,-2) -- ++(-1,-0.5) -- (\\date, \\ypos);%\n";
      output << "\\draw (\\date,1.5) node[scale=0.5]{\\nodeName};%\n%\n";

      Tcounter++;
  }
  output << "\\end{tikzpicture}%\n";
  output << "}\n";
         
  output.close();
  return 0;
}
