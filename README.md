# Peace-Treaty-Linux

Concept:
The general idea is to make a turn-based strategy game combining aspects of games like Civilizations, Hexonia, Lords Mobile, Rise of Kingdoms, and Infinity Kingdom with original ideas that I've come up with. Basically, the question is: What if we made a game with the semantics of a massively multiplayer strategy game like Lords Mobile but applied to the structure/procedures of a turn-based game like Civilizations? 

**Extra information

Background/Skill Level:
This project is extremely personal to me, as it is the first major project I've ever embarked on (relative to programs I've coded in class), which is why I'm adding this section. This project is based on a game I started my freshman year of high school in Computer Programming 1. That preliminary version of the game, fell through due to various reasons such as me being severely inexperienced as well trying to make a game with too wide a scope. I picked up the project idea towards the end of my Junior year, after taking AP Computer Science, and created "Fight for Emperor." This game/project is mainly built on the skills I learned in these two classes (Computer Programming 1 and AP Computer Science). Computer Programming 1 went over the proceural aspects of C++ like greating functions, passing objects, utilizing variable localization, and basic concepts like that (it was essentially a C course taught in C++). The scope of this class was extremely limited, with the course topics of study covering iteration, repetition, sequential order, and just barely getting to pointers and references. AP Computer Science expanded my knowledge, with me learning about classes, inheritance, and recursion. AP CS was taught in Java, but I carried what I learned over to C++ and used my newfound knowledge to start Fight for Emperor. As a senior, I'm taking Computer Programming 3, which is basically a self study class in which I learn about Computer Science topics at my own pace. As of now, I'm expanding on what I know through watching tutorials by the Cherno and studying LeetCode problems. As I've continued to work on the game and expand my skills and knowledge, the nature of the game has also evolved, which is why the project has been renamed to "Peace Treaty," which is intended to capture the nuances of the game beyond just fighting other players/AI.

Why is the Repo Called "Peace Treaty Linux?":
I started working on Fight For Emperor, not "Peace Treaty," on Repl.it (now Replit), an online IDE, as that's what I used to work on the original version of the game in 9th gradae. There was a period in of which I used Visual Studio as my main IDE when working on the project, but I switched back to Replit due to it being extremely portable as everything was online. After figuring out how to connect GitHub to the Repl, I've considered switching back to Visual Studio or VSCode as they're better environments to work in, but I found out the hard way that doing so would be extremely challenging. As I had to find out the hard way, Replit uses Linux as its operating system, whereas VSCode and Visual Studio use Windows. I thought this shouldn't matter beause the code should compile no matter what, but as it turned out, Linux and Windows use different containers when compiling code. This means that the code that I push and commit to Github through Repl are set in Linux containers, which don't run on VSCode or Visual Studio. Likewise, creating a project in either environment and pushing that repo to Github will result in the code being in Windows Containers, which won't run on Replit. I tried looking up what to do, and I saw that I can convert the containers using Docker, or something like that, but I haven't figured that out yet. What I have figured out, though, is that the code itself still works, so I copied and pasted each and every file in the Replit version and pasted it in a new Visual Studio project, which I pushed to Github as a new repo. I'm still working on Replit due to its portability, but I intend on switching to Visual Studio/VSCode after things get figured out. As a result, this Repo is the Replit-based version of the project, which uses Linux containers, hence the name "Peace Treaty Linux."

No Graphics?:
As mentioned above, this version of the project works in Replit, which uses Linux, so I can't use the Windows API to create frames or anything like that. Replit doesn't like using graphics stuff (in AP Computer Science, it wouldn't let me import various graphics files), so I'm basically stuck to the console, which is fine for the most part. Once I switch over to VSCode/VisualS Studio, I do intend on adding more graphics/visual content.