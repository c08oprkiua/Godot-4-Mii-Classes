# Godot-Mii-Module

This is a work in progress C++ Godot Module that aims to make working with Miis much easier, including:
* An easy to use `Resource`, 'MiiDataResource', for importing, creating, editing, and exporting Nintendo-valid Mii data

# MiiDataResource

The main part of this module, this `Resource` derivative allows for easy modification of values within a Mii. It features automatic behind-the-scenes checking for valid values, so you don't have to worry about accidentally setting out-of-range values. It also uses a memory model based on the Mii data format itself, making it quite memory friendly.

## Functions

### `LoadFromBuffer(buffer:PackedByteArray) -> void`

(Incomplete, non-working) This loads a PackedByteArray, `buffer`, of Mii data into the `MiiDataResource`. It can automatically detect file versions in order to properly load the data into the resource regardless on its version.

### `WriteToBuffer(output_device:Devices) -> PackedByteArray`

(Not implemented yet) Writes all the variables of the `MiiDataResource` instance to a valid mii data buffer, and returns it as a `PackedByteArray`. `output_device` is used to specify what kind of device the output Mii data will be for. If not set, it will default to whatever the origin device of the `MiiDataResource` is.

## To-do

- [ ] Importing:
  - [ ] Wii
  - [ ] DS
  - [ ] 3DS
  - [ ] Wii U / Switch
- [ ] Exporting:
  - [ ] Wii
  - [ ] DS
  - [ ] 3DS
  - [ ] Wii U / Switch
- [ ] "Generate Random Mii" type function 
- [ ] Improve in-engine docs

# MiiModel

A planned class derived from `Mesh`, which will use a `MiiDataResource` as a parameter set in order to provide a `Mesh` for rendering a Mii in 3D space.

## To-do
- [ ] Create
  
# MiiPortrait

A planned class derived from `Image` that will, like `MiiModel`, take a `MiiDataResource`, and render it in *2D* space as an image.

## To-do
- [ ] Create

# Thanks to:

* @aboood40091 for decompiling the FFL library (used for Miis on Wii U)
* [This github repo](https://github.com/HEYimHeroic/MiiDataFiles)/[This website](https://sites.google.com/view/miilibrary/contactfaqother/FAQ)
* The [3DS](https://www.3dbrew.org/wiki/Mii) and [Wii](https://wiibrew.org/wiki/Mii_data) wikis on the Mii data format
* AJ's Mii Editor
