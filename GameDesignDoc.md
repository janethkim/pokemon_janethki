# Game Design Document

## General Idea
My game will be something like Plants vs. Zombies. Think something like
a wave of monsters are coming, which you're going to have to prepare for.

## Things
  1. The enemy: will come toward your main defense line at different paces and at
      different times; the way I'm imagining it is for them to move horizontally across the 
      screen in the same direction (unless perhaps I implemented some other thing that would
      turn them around).
  1. A projectile shooter which will be placed where the user chooses. After that, it won't move.
      It will shoot bullets at the enemy when it sees it in its line of sight.
  1. The bullets ([fireballs] (Images/fireball.jpg)) that are shot by the projectile shooter. Depending on the type of projectile shooter,
      these bullets may be able to travel vertically or diagonally. The simplest bullet will simply
      shoot in the direction dictated by the projectile shooter. If time allows, it will rotate 
      as it moves across the screen.
  1. A bomb which will be placed where dictated by the user, and after a short amount of time, it
      will explode and kill/damage those around it within a certain radius. Maybe after using the bomb,
      though, the user will no longer be able to place anything there (kind of like a dead zone?)
  1. Some form of currency which the user will build up to buy more things to defend the main line.
      It will drop at random places around the screen, which the user will then click to pick up.
      Does this count as moving?
  1. Maybe if I have time, I will implement an additional item which the user can purchase; as a line
      of defense, it can be set as a trap, and when an enemy triggers it by stepping on it,
      it will run across the screen, killing everything in its way (moves horizontally across the
      screen, accelerating as it does so)
This is a place holder for your game design document. You are advised to write your document in [Markdown](http://daringfireball.net/projects/markdown/) and the following section will show you how to write a document using Markdown markup.

Alternativley, you can write your document in plain text if you wish.

----

## Markdown
Markdown is a human-readable structured plain text format that is used to convert text into HTML. GitHub automatically renders Markdown into HTML.

This is a crash course on how to use Markdown. The following section will show you the plain text used to generate the document shown in the rendering section.

### Code

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

