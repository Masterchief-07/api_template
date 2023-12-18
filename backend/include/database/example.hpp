#pragma once
#include <drogon/drogon.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <json/json.h>

namespace database{
    using DB_PTR = drogon::orm::DbClientPtr;
    class Example{

        public:
            uint id;
            std::string name;
        
        Example():id{0}, name{""}{};
        Example(uint id, std::string name): id{id}, name{name}{}

        Json::Value to_json();

        static Example getById(DB_PTR db, uint id);
        static Example getByName(DB_PTR db, std::string& data);
        static std::vector<Example> getAll(DB_PTR db);
        static bool addOne(DB_PTR db, Example &data);
        static bool updateOne(DB_PTR db, uint id, Example &data);
        static bool deleteOne(DB_PTR db, uint id);
    };

    Json::Value Example::to_json(){
        Json::Value data;
        data["id"] = id;
        data["name"] = name;

        return data;
    }
    Example Example::getById(DB_PTR db, uint id){

        Example data{};
        try{
            auto result = db->execSqlSync("SELECT * FROM examples WHERE id = ?", id);
            if (result.size() == 0) {return data;}
            data.id = result[0]["id"].as<uint>();
            data.name = result[0]["name"].as<std::string>();
        }
        catch (const drogon::orm::DrogonDbException &e){
            std::cerr<<e.base().what()<<std::endl;
        }
        return data;

    }
    Example Example::getByName(DB_PTR db,std::string& name){

        Example result{};

        try{
            auto result = db->execSqlSync("SELECT * FROM examples WHERE name = ?", name);
        }
        catch (const drogon::orm::DrogonDbException &e){
            std::cerr<<e.base().what()<<std::endl;
        }

        return result;
    }
    std::vector<Example> Example::getAll(DB_PTR db){
        std::vector<Example> all_data{};
        try{
            auto result = db->execSqlSync("SELECT * FROM examples");
            for (auto res:result)
            {
                Example data{};
                data.id = res["id"].as<uint>();
                data.name = res["name"].as<std::string>();
                all_data.push_back(data);
            }
        }
        catch (const drogon::orm::DrogonDbException &e){
            std::cerr<<e.base().what()<<std::endl;
        }
        return all_data;
    }
    bool Example::addOne(DB_PTR db, Example &data){
        try{
            auto result = db->execSqlSync("INSERT INTO examples (name) VALUES (?)", data.name);
            return true;
        }
        catch (const drogon::orm::DrogonDbException &e){
            std::cerr<<e.base().what()<<std::endl;
            return false;
        }
    }
    bool Example::updateOne(DB_PTR db, uint id, Example &data){
        try{
            auto result = db->execSqlSync("UPDATE examples SET name = ? WHERE id = ?", data.name, id);
            if (result.affectedRows() == 0){return false;}
            return true;
        }
        catch (const drogon::orm::DrogonDbException &e){
            std::cerr<<e.base().what()<<std::endl;
            return false;
        }
    }
    bool Example::deleteOne(DB_PTR db, uint id){
        try{
            auto result = db->execSqlSync("DELETE FROM examples WHERE id = ?", id);
            if (result.affectedRows() == 0) { return false;}
            return true;
        }
        catch (const drogon::orm::DrogonDbException &e){
            std::cerr<<e.base().what()<<std::endl;
            return false;
        }
    }
}