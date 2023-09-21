**Rust Assignment 1: Readme Document**  
**Programming Partners:** Nathaniel Brown, Jake Dansereau  

**Acknowledgement of Help:** Outside of working through particular problems with syntax and familarizing ourselves with a new language amongst the group partners; the majority of our outside help came from Teaching Assistants. In particular; Vincent Zhuang(x3), Nicholas(x1), Emily Light(x1), and Ayman Sandouk(x1).  

**__Vincent__** - Extremely helpful with clarification of some of the objectives of the assignment that caused confusion, as well as explaining core concepts of rust that are similar, but yet different from rust. As well as providing some supplementary background information on hashmaps in general that my group was rather weak with fully understanding before this assignment.  

**__Nicholas__** - Extremely helpful with instructing me how to properly look through the documentation of Rust, but more in particular the documentation of the 411csc_image module. Helped clarify things relating to the Gray type that was contained within the pixels vector, that caused a major barrier to the brightness assignment. Also provided some background information on error handling with the options system related to rust.  

**__Emily__** - Extremely helpful with providing supplementary information in the form of a mini-lecture with my group and other members of the 411 class in the Tyler lonuge. Helped provide a much better understanding of result, in particular options (some/none).  

**__Ayman__** - Extremely helpful with helping guide me towards better ways to troubleshoot my code when grade scope does not provide test cases that get me to the finish line. Instead; he proposed methodologies that could be used to find those issues on my own. (Which immediately lead to the detection of a major flaw in an earlier version of my program.)  
  
**PART C:** Problems you can solve using a working version of fgroups **:PART C**  
   
**1.)** Support Tickets; suppose a fictitious company has a support department where customers are able to submit tickets for support from the company. Naturally some issues will have greater importance than others. If tickets were submitted with a 'Priority' label indiciating whether it is High, Medium, or Low urgency. Followed by an 'Issue Identifier' which could be selected or filled out from the user. You would effectively sort your issues into a hashmap containing keys (the level of urgency) and values (issues within each urgency group). This could easily be implemented with the fgroups program; although it could be expanded by changing our names:values to an object that contains more prevelant member variables and information to the Issue submitted in this fictitious company.  
  
**2.)** Library Management; perhaps a library wishes to actually know what inventory they have. Rather than just have a giant disorganized collection of all books within their collection. You can have books sorted by Genres, which would be our keys, and Books, which would be our values. After reading a giant file containing all of the books and associating them with a genre identifier. The library would now have access to every book in their collection, organized by genre. This would easily be implemented using the fgroups program as it stands currently; again it could be expanded though. Perhaps by expanding the program to include a basic user interface, in which the user could search for a specific book and have returned the genre it's categorized under.  
  
**3.)**
