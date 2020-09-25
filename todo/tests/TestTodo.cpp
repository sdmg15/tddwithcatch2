#include "../../include/catch2/catch2.hpp"
#include <algorithm>
#include <functional>
#include "../Todo.hpp"


Todo::Todo td;

TEST_CASE("Adding new tasks to the todo list","[ADD TASK]"){

    REQUIRE( td.tasks().size() == 0);

    td.makeTask("My new task", "The description", Todo::Priority::HIGH)
      .makeTask("Another task", "Another description", Todo::Priority::MEDUIM)
      .makeTask("Another awesome task", "Here is the description", Todo::Priority::LOW)
      .makeTask("A task with high priority at the bottom", "Here is the description", Todo::Priority::HIGH);

    REQUIRE( td.tasks().size() == 4 );   
}

TEST_CASE("Deleting a task from the todo list", "[DELETE TASK]"){
    auto oldSize = td.tasks().size();

    SECTION("Deleting element and it succeeds"){
        td.deleteTask(1);
        REQUIRE( td.tasks().size() == oldSize - 1 );
    }

    SECTION("Deleting element and it does not succeed"){
        td.deleteTask(3);
        REQUIRE( td.tasks().size() == oldSize );
    }    
}

TEST_CASE("Sorting tasks by priority", "[SORTING TASKS]"){
    td.sortByPriority();
    bool isSorted = std::is_sorted(td.tasks().cbegin(), td.tasks().cend());
    REQUIRE( isSorted == true );
    td.printTasks();
}