#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
#include<vector>

const std::string NPOS1="Meaing not defined";
const std::string NPOS2="not found";
const char delim=';';
class Dictionary{
    private:

        struct TrieNode{
            std::vector<struct TrieNode*>children;
            bool isEnd=false;
            std::string key="";
        };
        struct TrieNode *root=nullptr;

        TrieNode* insert(std::string word,std::string meaning,TrieNode* node){
            if(node==nullptr){
                node=new TrieNode;
                node->children.resize(26,nullptr);
                if(word.size()==0){
                    node->isEnd=true;
                    node->key=meaning;
                    return node;
                }else{
                    unsigned int index = static_cast<unsigned int>(word[0])-97;
                    word.erase(word.begin());
                    node->children[index]=insert(word,meaning,node->children[index]);
                    return node;
                }
            }else{
                if(word.size()==0){
                    node->isEnd=true;
                    node->key=meaning;
                    return node;
                }else{
                    unsigned int index = static_cast<unsigned int>(word[0])-97;
                    word.erase(word.begin());
                    node->children[index]=insert(word,meaning,node->children[index]);
                    return node;
                }
            }
        }
        std::string find(std::string  word,TrieNode* node){
            if(word.size()==0){
                if(node->isEnd){
                    return node->key;
                }else{
                    return NPOS1;
                }
            }else{
                unsigned int index = static_cast<unsigned int>(word[0])-97;
                word.erase(word.begin());
                if(node->children[index]!=nullptr) return find(word,node->children[index]);
                else return NPOS2;
            }
        }

    public:
        Dictionary(){
            root=new TrieNode;
            root->children.resize(26,nullptr);
        }
        void insert(std::string word,std::string meaning){

            transform(word.begin(),word.end(),word.begin(),::tolower);
            root=insert(word,meaning,root);
        }
        std::string find(std::string word){
            return find(word,root);
        }
        TrieNode* getRoot(){
            return root;
        }
        void read(){

            QFile file("C:\\Users\\Vineeth\\Desktop\\New folder\\Dictionary.pro");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    return;
            QTextStream in(&file);
                while (!in.atEnd()) {
                    QString Qline = in.readLine();
                    std::string line = Qline.toUtf8().constData();
                    std::string a,b;
                    std::stringstream row(line);
                    std::getline(row,a,delim);
                    std::getline(row,b,delim);
                    insert(a,b);
                }
        }
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
  Ui::MainWindow *ui;
Dictionary dic;
private slots:
    void on_pushButton_clicked();
public: 
explicit MainWindow(QWidget *parent = nullptr);
~MainWindow();
};

#endif // MAINWINDOW_H
