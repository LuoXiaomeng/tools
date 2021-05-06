#include  <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "pugixml.hpp"
using namespace std;

void split_all(){
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file("/mnt/c/Users/luoxm/Downloads/dblp.xml");

    pugi::xpath_node_set articles = doc.select_nodes("/dblp/article");
    pugi::xpath_node_set inproceedings = doc.select_nodes("/dblp/inproceedings");
    pugi::xpath_node_set proceedings = doc.select_nodes("/dblp/proceedings");
    pugi::xpath_node_set book = doc.select_nodes("/dblp/book");
    pugi::xpath_node_set incollection = doc.select_nodes("/dblp/incollection");
    pugi::xpath_node_set phdthesis = doc.select_nodes("/dblp/phdthesis");
    pugi::xpath_node_set mastersthesis = doc.select_nodes("/dblp/mastersthesis");
    pugi::xpath_node_set www = doc.select_nodes("/dblp/www");
    pugi::xpath_node_set person = doc.select_nodes("/dblp/person");
    pugi::xpath_node_set data = doc.select_nodes("/dblp/data");

    cout<<articles.size()<<endl;
    cout<<inproceedings.size()<<endl;
    cout<<proceedings.size()<<endl;
    cout<<book.size()<<endl;
    cout<<incollection.size()<<endl;
    cout<<phdthesis.size()<<endl;
    cout<<mastersthesis.size()<<endl;
    cout<<www.size()<<endl;
    cout<<person.size()<<endl;
    cout<<data.size()<<endl;

    pugi::xml_document a_doc;
    pugi::xml_document ip_doc;
    pugi::xml_document pro_doc;
    pugi::xml_document b_doc;
    pugi::xml_document ic_doc;
    pugi::xml_document phd_doc;
    pugi::xml_document m_doc;
    pugi::xml_document w_doc;
    pugi::xml_document per_doc;
    pugi::xml_document d_doc;

    a_doc.append_child("dblp");
    ip_doc.append_child("dblp");
    pro_doc.append_child("dblp");
    b_doc.append_child("dblp");
    ic_doc.append_child("dblp");
    phd_doc.append_child("dblp");
    m_doc.append_child("dblp");
    w_doc.append_child("dblp");
    per_doc.append_child("dblp");
    d_doc.append_child("dblp");

    for (pugi::xpath_node_set::const_iterator it = articles.begin(); it != articles.end(); ++it)
    {
        pugi::xpath_node node = *it;
        a_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    a_doc.save_file("dblp_article.xml");
    a_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = inproceedings.begin(); it != inproceedings.end(); ++it)
    {
        pugi::xpath_node node = *it;
        ip_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    ip_doc.save_file("dblp_inproceedings.xml");
    ip_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = proceedings.begin(); it != proceedings.end(); ++it)
    {
        pugi::xpath_node node = *it;
        pro_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    pro_doc.save_file("dblp_proceedings.xml");
    pro_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = book.begin(); it != book.end(); ++it)
    {
        pugi::xpath_node node = *it;
        b_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    b_doc.save_file("dblp_book.xml");
    b_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = incollection.begin(); it != incollection.end(); ++it)
    {
        pugi::xpath_node node = *it;
        ic_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }
    
    ic_doc.save_file("dblp_incollection.xml");
    ic_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = phdthesis.begin(); it != phdthesis.end(); ++it)
    {
        pugi::xpath_node node = *it;
        phd_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    phd_doc.save_file("dblp_phdthesis.xml");
    phd_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = mastersthesis.begin(); it != mastersthesis.end(); ++it)
    {
        pugi::xpath_node node = *it;
        m_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    m_doc.save_file("dblp_masterthesis.xml");
    m_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = www.begin(); it != www.end(); ++it)
    {
        pugi::xpath_node node = *it;
        w_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    w_doc.save_file("dblp_www.xml");
    w_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = person.begin(); it != person.end(); ++it)
    {
        pugi::xpath_node node = *it;
        per_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }

    per_doc.save_file("dblp_person.xml");
    per_doc.reset();

    for (pugi::xpath_node_set::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        pugi::xpath_node node = *it;
        d_doc.child("dblp").append_copy(node.node()); 
        doc.child("dblp").remove_child(node.node());
    }
    
    d_doc.save_file("dblp_data.xml");
    d_doc.reset();
    
    std::cout << "Load result: " << result.description() << std::endl;

    /*
    2419010
    2719869
    45813
    18387
    65873
    78613
    12
    2635851
    0
    0
    Load result: No error
    */
}

void split_author(){
    pugi::xml_document doc;

    doc.load_file("/mnt/c/Users/luoxm/Desktop/XMLReader/build/dblp_www.xml");
    auto www = doc.child("dblp");

    pugi::xml_document a_doc;
    pugi::xml_document w_doc;
    pugi::xml_document ad_doc;

    a_doc.append_child("dblp");
    w_doc.append_child("dblp");
    ad_doc.append_child("dblp");

    int a_size=0;
    int ad_size=0;
    int w_size=0;

    for (pugi::xml_node w = www.first_child(); w; w = w.next_sibling())
    {
        if(strcmp("Home Page",w.child_value("title"))){
            w_doc.child("dblp").append_copy(w); 
            // doc.child("dblp").remove_child(w);
            w_size++;
            continue;
        }
        if(strcmp("disambiguation",w.attribute("publtype").value())){
            a_doc.child("dblp").append_copy(w); 
            // doc.child("dblp").remove_child(w);
            a_size++;
            continue;
        }
        ad_doc.child("dblp").append_copy(w); 
        // doc.child("dblp").remove_child(w);
        ad_size++;
    }

    a_doc.save_file("dblp_www_author.xml");
    ad_doc.save_file("dblp_www_authorDisambiguation.xml");
    w_doc.save_file("dblp_www_web.xml");

    cout<<a_size<<endl;
    cout<<ad_size<<endl;
    cout<<w_size<<endl;
    /*
    2626693
    8740
    418
    */
}

void author_to_db(){
    pugi::xml_document doc;

    std::ofstream of_author ("author.csv", std::ofstream::out);
    std::ofstream of_award ("award.csv", std::ofstream::out);
    std::ofstream of_affiliation ("affiliation.csv", std::ofstream::out);
    std::ofstream of_author_link ("author_link.csv", std::ofstream::out);
    std::ofstream of_author_award ("author_award.csv", std::ofstream::out);
    std::ofstream of_author_affiliaation ("author_affiliaation.csv", std::ofstream::out);
    std::ofstream of_name ("name.csv", std::ofstream::out);

    int auth_id = 0;
    int award_id = 0;
    int aff_id = 0;

    doc.load_file("/mnt/c/Users/luoxm/Desktop/XMLReader/build/dblp_www_author.xml");
    auto authors = doc.child("dblp");
    for (pugi::xml_node author = authors.first_child(); author; author = author.next_sibling())
    {
        auth_id++;
        string uname;

        of_author<<auth_id<<"|"<<author.attribute("key").value()<<"|"<<author.attribute("mdate").value();

        auto names = author.children("author");
        for(auto a = names.begin();a!=names.end();a++){
            of_name<<auth_id<<"|"<<a->text().get()<<endl;
        }
        auto notes = author.children("note");
        for(auto n = notes.begin();n!=notes.end();n++){
            char* type = (char*)n->attribute("type").value();
            char* label = (char*)n->attribute("label").value();
            if(strcmp(type,"affiliation")==0){
                aff_id++;
                of_affiliation<<aff_id<<"|"<<n->text().get()<<endl;
                of_author_affiliaation<<auth_id<<"|"<<aff_id<<"|"<<label<<endl;
            }else if(strcmp(type,"award")==0){
                award_id++;
                of_award<<award_id<<"|"<<n->text().get()<<endl;
                of_author_award<<auth_id<<"|"<<award_id<<"|"<<label<<endl;
            }else if(strcmp(type,"uname")==0){
                if(!uname.empty())uname+=",";
                uname+=n->text().get();
            }
        }
        auto urls = author.children("url");
        for(auto u = urls.begin();u!=urls.end();u++){
            of_author_link<<auth_id<<"|"<<u->text().get()<<endl;
        }
        of_author<<"|"<<uname<<endl;
    }
    of_author.close();
    of_award.close();
    of_affiliation.close();
    of_author_link.close();
    of_author_award.close();
    of_author_affiliaation.close();
    of_name.close();
}

void article_to_db(){
    pugi::xml_document doc;
    doc.load_file("/mnt/c/Users/luoxm/Desktop/XMLReader/build/dblp_article.xml");

    std::ofstream of_article ("article.csv", std::ofstream::out);
    std::ofstream of_journal ("journal.csv", std::ofstream::out);
    std::ofstream of_article_link ("article_link.csv", std::ofstream::out);
    std::ofstream of_article_author ("article_author.csv", std::ofstream::out);
    std::ofstream of_article_cite ("article_cite.csv", std::ofstream::out);

    int journal_id = 0;
    int article_id = 0;

    auto articles = doc.child("dblp");

    for(auto article = articles.first_child();article; article = article.next_sibling()){
        article_id++;
        of_article<<article_id<<"\t"<<article.attribute("key").value()<<"\t"<<article.attribute("mdate").value()<<"\t"<<article.attribute("publtype").value()<<"\t"<<article.child_value("title")<<"\t"<<article.child_value("year")<<"\t"<<article.child_value("month")<<"\t";
        auto authors = article.children("author");
        for(auto author = authors.begin();author!=authors.end();author++){
            of_article_author<<article_id<<"\t"<<author->text().get()<<"\t"<<author->attribute("orcid").value()<<endl;
        }
        auto links = article.children("ee");
        for(auto ee = links.begin();ee!=links.end();ee++){
            of_article_link<<article_id<<"\t"<<ee->text().get()<<endl;
        }
        auto journals = article.children("journal");
        int i=0;
        for(auto journal = journals.begin();journal!=journals.end();journal++){
            journal_id++;
            if(i!=0)of_article<<",";
            of_article<<journal_id;
            of_journal<<journal_id<<"\t"<<journal->text().get()<<endl;
            i++;
        }
        auto cites = article.children("cite");
        for(auto cite = cites.begin();cite!=cites.end();cite++){
            char* c = (char*)cite->text().get();
            if(strcmp("...",c)){
                of_article_cite<<article_id<<"\t"<<c<<endl;
            }
        }
        of_article<<"\t"<<article.child_value("volumn")<<"\t"<<article.child_value("number")<<"\t"<<article.child_value("pages")<<endl;
    }
}

void inproceeding_to_db(){
    pugi::xml_document doc;
    doc.load_file("/mnt/c/Users/luoxm/Desktop/XMLReader/build/dblp_inproceedings.xml");

    std::ofstream of_inproceedings ("inproceedings.csv", std::ofstream::out);
    std::ofstream of_inproceedings_editor ("inproceedings_editor.csv", std::ofstream::out);
    std::ofstream of_inproceedings_link ("inproceedings_link.csv", std::ofstream::out);
    std::ofstream of_inproceedings_author ("inproceedings_author.csv", std::ofstream::out);
    std::ofstream of_inproceedings_cite ("inproceedings_cite.csv", std::ofstream::out);

    int inproceedings_id = 0;

    auto inproceedings = doc.child("dblp");

    for(auto inproceeding = inproceedings.first_child();inproceeding; inproceeding = inproceeding.next_sibling()){
        inproceedings_id++;
        of_inproceedings<<inproceedings_id<<"\t"<<inproceeding.attribute("key").value()<<"\t"<<inproceeding.attribute("mdate").value()<<"\t"<<inproceeding.attribute("publtype").value()<<"\t";
        of_inproceedings<<inproceeding.child_value("title")<<"\t"<<inproceeding.child_value("year")<<"\t"<<inproceeding.child_value("month")<<"\t";
        of_inproceedings<<inproceeding.child_value("booktitle")<<"\t"<<inproceeding.child_value("volume")<<"\t"<<inproceeding.child_value("number")<<"\t"<<inproceeding.child_value("pages")<<"\t";
        of_inproceedings<<inproceeding.child_value("cdrom")<<"\t"<<inproceeding.child_value("crossref")<<"\t";
        auto authors = inproceeding.children("author");
        for(auto author = authors.begin();author!=authors.end();author++){
            of_inproceedings_author<<inproceedings_id<<"\t"<<author->text().get()<<"\t"<<author->attribute("orcid").value()<<endl;
        }
        auto editors = inproceeding.children("editor");
        for(auto editor = editors.begin();editor!=editors.end();editor++){
            of_inproceedings_editor<<inproceedings_id<<"\t"<<editor->text().get()<<"\t"<<editor->attribute("orcid").value()<<endl;
        }
        auto links = inproceeding.children("ee");
        for(auto ee = links.begin();ee!=links.end();ee++){
            of_inproceedings_link<<inproceedings_id<<"\t"<<ee->text().get()<<endl;
        }
        auto notes = inproceeding.children("note");
        int i=0;
        for(auto note = notes.begin();note!=notes.end();note++){
            if(i!=0)of_inproceedings<<",";
            of_inproceedings<<note->text().get();
            i++;
        }
        auto cites = inproceeding.children("cite");
        for(auto cite = cites.begin();cite!=cites.end();cite++){
            char* c = (char*)cite->text().get();
            if(strcmp("...",c)){
                of_inproceedings_cite<<inproceedings_id<<"\t"<<c<<"\t"<<cite->attribute("label").value()<<endl;
            }
        }
        of_inproceedings<<endl;
    }
}

void proceeding_to_db(){
    pugi::xml_document doc;
    doc.load_file("/mnt/c/Users/luoxm/Desktop/XMLReader/build/dblp_proceedings.xml");

    std::ofstream of_proceedings ("proceedings.csv", std::ofstream::out);
    std::ofstream of_proceedings_editor ("proceedings_editor.csv", std::ofstream::out);
    std::ofstream of_proceedings_link ("proceedings_link.csv", std::ofstream::out);
    std::ofstream of_proceedings_author ("proceedings_author.csv", std::ofstream::out);
    std::ofstream of_proceedings_cite ("proceedings_cite.csv", std::ofstream::out);
    std::ofstream of_proceedings_isbn ("proceedings_isbn.csv", std::ofstream::out);
    std::ofstream of_proceedings_booktitle ("proceedings_booktitle.csv", std::ofstream::out);
    std::ofstream of_publisher ("publisher.csv", std::ofstream::out);
    std::ofstream of_series ("series.csv", std::ofstream::out);

    int proceedings_id = 0;
    int booktitle_id = 0;
    int publisher_id = 0;
    int series_id = 0;

    auto proceedings = doc.child("dblp");

    for(auto proceeding = proceedings.first_child();proceeding; proceeding = proceeding.next_sibling()){
        proceedings_id++;

        of_proceedings<<proceedings_id<<"\t"<<proceeding.attribute("key").value()<<"\t"<<proceeding.attribute("mdate").value()<<"\t"<<proceeding.attribute("publtype").value()<<"\t";
        of_proceedings<<proceeding.child_value("title")<<"\t"<<proceeding.child_value("year")<<"\t";
        
        auto authors = proceeding.children("author");
        for(auto author = authors.begin();author!=authors.end();author++){
            of_proceedings_author<<proceedings_id<<"\t"<<author->text().get()<<"\t"<<author->attribute("orcid").value()<<endl;
        }
        auto editors = proceeding.children("editor");
        for(auto editor = editors.begin();editor!=editors.end();editor++){
            of_proceedings_editor<<proceedings_id<<"\t"<<editor->text().get()<<"\t"<<editor->attribute("orcid").value()<<endl;
        }
        auto links = proceeding.children("ee");
        for(auto ee = links.begin();ee!=links.end();ee++){
            of_proceedings_link<<proceedings_id<<"\t"<<ee->text().get()<<endl;
        }
        auto cites = proceeding.children("cite");
        for(auto cite = cites.begin();cite!=cites.end();cite++){
            char* c = (char*)cite->text().get();
            if(strcmp("...",c)){
                of_proceedings_cite<<proceedings_id<<"\t"<<c<<"\t"<<cite->attribute("label").value()<<endl;
            }
        }
        auto isbns = proceeding.children("isbn");
        for(auto isbn = isbns.begin();isbn!=isbns.end();isbn++){
            of_proceedings_isbn<<proceedings_id<<"\t"<<isbn->text().get()<<endl;
        }

        auto booktitles = proceeding.children("booktitle");
        int i=0;
        for(auto booktitle = booktitles.begin();booktitle!=booktitles.end();booktitle++){
            if(i>0)cout<<"booktitle error at "<<proceeding.attribute("key").value()<<endl;
            booktitle_id++;
            of_proceedings_booktitle<<booktitle_id<<"\t"<<booktitle->text().get()<<endl;
            of_proceedings<<booktitle_id<<"\t";
            i++;
        }

        auto journals = proceeding.children("journal");
        for(auto journal = journals.begin();journal!=journals.end();journal++){
            of_proceedings<<"817080"<<"\t";
        }

        auto publishers = proceeding.children("publisher");
        i=0;
        for(auto publisher = publishers.begin();publisher!=publishers.end();publisher++){
            // if(i>0)cout<<"publisher error at "<<proceeding.attribute("key").value()<<endl;
            if(i>0)break;
            publisher_id++;
            of_publisher<<publisher_id<<"\t"<<publisher->text().get()<<endl;
            of_proceedings<<publisher_id<<"\t";
            i++;
        }

        of_proceedings<<proceeding.child_value("address")<<"\t"<<proceeding.child_value("volume")<<"\t"<<proceeding.child_value("number")<<"\t"<<proceeding.child_value("pages")<<"\t";

        auto seriess = proceeding.children("series");
        i=0;
        for(auto series = seriess.begin();series!=seriess.end();series++){
            // if(i>0)cout<<"series error at "<<proceeding.attribute("key").value()<<endl;
            if(i>0)break;
            series_id++;
            of_series<<series_id<<"\t"<<series->text().get()<<endl;
            of_proceedings<<series_id<<"\t";
            i++;
        }
        
        auto notes = proceeding.children("note");
        i=0;
        for(auto note = notes.begin();note!=notes.end();note++){
            char* type = (char*)note->attribute("type").value();
            if(strcmp(type,"isbn")){
                if(i>0)of_proceedings<<";";
                of_proceedings<<note->text().get();
                i++;
            }else{
                of_proceedings_isbn<<proceedings_id<<"\t"<<note->text().get()<<endl;
            }
        }
        of_proceedings<<endl;
    }

    /*
    dup:
    publisher error at conf/openidentity/2017
    publisher error at conf/ifip/1959
    publisher error at conf/ifip/1959
    series error at conf/f-egc/2017
    */
}

void author_disambiguation_to_db(){
    pugi::xml_document doc;

    std::ofstream of_author_disambiguation ("author_disambiguation.csv", std::ofstream::out);
    std::ofstream of_name_ambiguation ("name_ambiguation.csv", std::ofstream::out);

    int auth_id = 0;

    doc.load_file("/mnt/c/Users/luoxm/Desktop/XMLReader/build/dblp_www_authorDisambiguation.xml");
    auto authors = doc.child("dblp");
    for (pugi::xml_node author = authors.first_child(); author; author = author.next_sibling())
    {
        auth_id++;
        string uname;

        of_author_disambiguation<<auth_id<<"\t"<<author.attribute("key").value()<<"\t"<<author.attribute("mdate").value()<<endl;

        auto names = author.children("author");
        for(auto a = names.begin();a!=names.end();a++){
            of_name_ambiguation<<auth_id<<"\t"<<a->text().get()<<endl;
        }

    }
    of_author_disambiguation.close();
    of_name_ambiguation.close();
}


int main(){
    author_disambiguation_to_db();
    return 0;
}