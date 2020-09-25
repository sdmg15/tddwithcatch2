#ifndef TODO_HEADER_INCLUDE
#define TODO_HEADER_INCLUDE
#endif

#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>

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
        friend bool operator<(const Task& lhs, const Task& rhs){
            return static_cast<int>(lhs.priority_) < static_cast<int>(rhs.priority_);
        }
    };
    
    struct Todo {

        std::vector<Task> tasks_;

        auto makeTask(std::string_view t, std::string_view desc, 
                     const Priority p = Priority::NONE, const Status s = Status::NONE) noexcept -> Todo& {
            
            Task task;

            task.title_ = t.data();
            task.priority_ = p;
            task.desc_ = desc;
            task.status_ = s;

            tasks_.emplace_back(task);

            return *this;
        }

        auto deleteTask(TaskID taskID) noexcept -> Todo& {

            if( tasks_.size() < taskID ){
                std::cout << "Out of range ... \n";
            }else{
                auto toDeleteIt = tasks_.begin() + taskID;
                tasks_.erase(toDeleteIt);
            }

            return *this;
        }

        auto tasks() const noexcept -> std::vector<Task> {
            return tasks_;
        } 

        template<typename Predicate = std::less<>>
        auto sortByPriority() -> void {
            std::sort( tasks_.begin(), tasks_.end(), [](const auto& t1, const auto& t2){
                return Predicate()(t1.priority_, t2.priority_);
            });
        }

        auto printTasks() -> void {
            std::for_each(tasks_.cbegin(), tasks_.cend(), [](const auto& t ){
                std::cout << "[" << t.title_ << "] - [" << static_cast<int>(t.priority_) << "] \n";
            });
        }
    };

}