# Attorney Online

[Attorney Online](https://aceattorneyonline.com) is an online version of an Ace Attorney-esque game.

This fork is referred to as "AO Classic" and accompanies [tsuserver3 Origin](https://github.com/argoneuscze/tsuserver3_origin).

---

## Basic features

### In-character chat

Type in a message in the gray box under the viewport, select an emote, and press Enter.

### Emotes

An emote represents a set of animations played while the character is speaking and idle. Some emotes also contain a preanimation, which is played before the text is said by the character.

### Interjections (shouts)

Select an interjection to toggle it. When you send a message, it will interrupt all other dialogue and interject with your message.

### Out-of-character chat

This is a general-purpose chat isolated within areas to discuss matters without interrupting cases. You must enter a name before chatting.

### Music list

Double-click a track to play it. Some servers automatically loop the track. Green tracks are available locally; red tracks are not.

### Areas

Servers have multiple areas to hold multiple cases simultaneously. Double-click an area in the music list to switch to it. (The reason that
areas are in the music list is a historical one.)

### Judge controls

The judge can set health bars and play the Witness Testimony, Cross Examination, Guilty, and Not Guilty animations.

### Mod calls

Calling a mod notifies moderators currently in the server of an incident. (Mod call reasons require 2.6+ server-side support.) Logged-in moderators can toggle the Guard option to be notified of mod calls.

### Muting

Click on a character in the mute list to ignore any in-character chat from the specified character.

### Positions

All characters have a default position within the courtroom, but they can nonetheless be changed within the interface.

Available positions:

- `def` - Defense
- `pro` - Prosecution
- `hld` - Helper defense
- `hlp` - Helper prosecution
- `jud` - Judge
- `wit` - Witness

## Advanced features

### Markup language

#### Color

Wrapping text with these characters will set the text inside of them to the associated color.

- `(` and `)` (parentheses) - blue
- \` (backtick) - green
- `|` (vertical bar) - orange
- `[` and `]` (square brackets) - grey

#### Speed

Type `{` to slow down the text a bit, and `}` to speed it up. This takes effect after the character has been typed, so the text may take up different speeds at different points. Both of these can be stacked up to three times, and even against each other.

Example:
```
Hello there! This text goes at normal speed.} Now, it's a bit faster!{ Now, it's back to normal.}}} Now it goes at maximum speed! {{Now it's only a little bit faster than normal.
```

#### Position

If you begin a message with `~~` (two tildes), the two tildes are removed and the message is centered.

#### Screenshake / Realization

Type `@` to apply screenshake, or `$` to apply realization ("ding") at any part of your message.

### Pairing

If two players are in the same position and select each other's characters using the in-game pair list, they will appear alongside each other. You can set the offset of your character using the provided spinbox.

### Non-interrupting preanimations

When checked, this will force text to immediately begin displaying without waiting for the preanimation to finish.

### Custom IC names (shownames)

You can set a custom in-character name using the provided text box. An option in the interface is also present to disable custom IC names for other players to prevent impersonation.

### Extended area support

Areas can be listed by clicking the A/M button. The statuses of such areas are displayed (and updated automatically).
