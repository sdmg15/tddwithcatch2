#ifndef TODO_HEADER_INCLUDE
#define TODO_HEADER_INCLUDE
#endif

#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <map>
#include <utility>

namespace Todo{

using TaskID = int;

    enum class Priority : char{
        LOW,
        MEDUIM,
        HIGH,
        MORTAL,
        NONE,
    };

    enum class Status: char{
        DONE,
        DOING,
        DELETED,
        WONTDO,
        NONE,
    };    

    struct Task {

        std::string title_;
        Priority priority_;
        std::string desc_;
        Status status_;

    };
    
    struct Todo {

        std::map<TaskID, Task> tasks_;

        auto makeTask(std::string_view t, std::string_view desc, 
                     const Priority p = Priority::NONE, const Status s = Status::NONE) noexcept -> Todo& {
            
            Task task;

            task.title_ = t.data();
            task.priority_ = p;
            task.desc_ = desc;
            task.status_ = s;

            auto newID = tasks_.size() + 1;

            tasks_.emplace( std::make_pair(newID, task));

            return *this;
        }

        auto deleteTask(TaskID taskID) noexcept(false) -> Todo& {

            auto foundElem = tasks_.find( taskID );

            if( foundElem != tasks_.end() ){
                tasks_.erase(  foundElem ); 
            }else{
                std::cout << "Element not found exiting ... \n";
            }
            return *this;
        }

        auto tasks() const noexcept -> std::map<TaskID, Task> {
            return tasks_;
        } 

    };

}