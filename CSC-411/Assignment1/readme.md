**Rust Assignment 1 Readme.md  PART C**
Nathaniel Brown
9/21/2023

Problems you can solve using a working version of fgroups:  
  
**1.)** Support Tickets; suppose a fictitious company has a support department where customers are able to submit tickets for support from the company. Naturally some issues will have greater importance than others. If tickets were submitted with a 'Priority' label indiciating whether it is High, Medium, or Low urgency. Followed by an 'Issue Identifier' which could be selected or filled out from the user. You would effectively sort your issues into a hashmap containing keys (the level of urgency) and values (issues within each urgency group). This could easily be implemented with the fgroups program; although it could be expanded by changing our names:values to an object that contains more prevelant member variables and information to the Issue submitted in this fictitious company.  
  
**2.)** Library Management; perhaps a library wishes to actually know what inventory they have. Rather than just have a giant disorganized collection of all books within their collection. You can have books sorted by Genres, which would be our keys, and Books, which would be our values. After reading a giant file containing all of the books and associating them with a genre identifier. The library would now have access to every book in their collection, organized by genre. This would easily be implemented using the fgroups program as it stands currently; again it could be expanded though. Perhaps by expanding the program to include a basic user interface, in which the user could search for a specific book and have returned the genre it's categorized under.  
  
**3.)**
