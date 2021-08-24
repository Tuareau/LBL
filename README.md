# LBL
Light Ball League

![Main Window Model](https://github.com/Tuareau/LBL/raw/develop/window_model.png)

## Description
A small desktop application development project. The application will allow you to create three types of tournaments: league, a group tournament and a single-elimination tournament. Multi-user work will be available. All tournaments last for the seasons that the user goes through. The application will provide an overview of statistics, lists of tournaments and teams, possibly the history of championships.

## Tools
We use C++1x/STL, Qt and MS Visual Studio.

## Classes model
While searching for a team and studying Qt, the developers are writing a small kernel. It implements a simple model of the class hierarchy:

- Season class: tracks the status of tournaments
- Tournament class: initializes the tournament and changes its state

- Schedule and Table class: match schedule and table

- League class: one of three possible tournaments, contains a list of teams and pointers to the objects that control the league
- LeagueSchedule class: makes the schedule and manages the games
- LeagueTable class: updates information about the status of teams
- Matchday class: a "package" of information received from LeagueSchedule and transmitted to LeagueTable via the League class

## Current tasks
1) Develop a GUI to create leagues, display game days and tables
2) Supplement the application with other types of tournaments
3) Create a mechanism for collecting statistics
4) Implement user accounts
