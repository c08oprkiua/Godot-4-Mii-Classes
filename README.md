# Godot-4-Mii-Classes

This is a work in progress C++ Godot Module that aims to make working with Miis much easier. Currently, it adds a custom class, `MiiDataResource`, to Godot 4 (Currently tested on 4.2.x), which extends from `Resource`.

In the future, I also plan to add a custom 3D model class, which will take the aforementioned resource as an input, and accordingly render an accurate Mii. I also might add something akin for getting a 2D portrait of the Mii.

# Functions

### `LoadFromBuffer(buffer: PackedByteArray)`

(Incomplete, non-working) This takes a PackedByteArray, `buffer`, of Mii data and writes all the data of it to the variables of the `MiiDataResource` it is called on. Currently, this expects the most recent revision of the Mii data spec (used by the Wii U and Switch), but future support is planned for older revisions.

### `WriteToBuffer()`

(Not implemented yet) Writes all the variables of the `MiiDataResource` instance to a valid mii data buffer, and returns it as a `PackedByteArray`. 

# To-do/roadmap

- [x] ~~Add To-do list~~

## `MiiDataResource`:

- [ ] Functions:
  - [ ] `LoadBuffer`
  - [ ] `WriteToBuffer`
  - [ ] "Generate Random Mii" type function 
- [ ] Clamp variables to valid ranges
  - [ ] Meta
  - [ ] General
  - [ ] Face Misc.
  - [x] Hair
  - [x] Eyes
  - [x] Eyebrows
  - [x] Nose
  - [x] Mouth
  - [x] Facial Hair
  - [x] Glasses
  - [x] Mole
- [ ] Implement variables:
  - [ ] Meta
  - [ ] General
  - [ ] Face Misc.
  - [x] Hair
  - [x] Eyes
  - [x] Eyebrows
  - [x] Nose
  - [x] Mouth
  - [x] Facial Hair
  - [x] Glasses
  - [x] Mole
- [ ] Improve in-engine docs
  
  ## `MiiModel`
- [ ] Create
  
  ## `MiiPortrait`
- [ ] Create

# Thanks to:

* @aboood40091 for decompiling the FFL library (used for Miis on Wii U)
* [This github repo](https://github.com/HEYimHeroic/MiiDataFiles)/[This website](https://sites.google.com/view/miilibrary/contactfaqother/FAQ)
* The [3DS](https://www.3dbrew.org/wiki/Mii) and [Wii](https://wiibrew.org/wiki/Mii_data) wikis on the Mii data format
* AJ's Mii Editor
