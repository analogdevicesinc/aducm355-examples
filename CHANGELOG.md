ADuCM355 Examples Change log
==========================

## 0.2.0(Ongoing)

### Added
* Add .ewd file extension to iar folder to all projects to select J-Link as default debug interface
* Add README and gitignore
* Add license
* 

### Changed
* Changed comment in M355_GPIO.c to indicate correct baud rate setting of 230400


### Removed
* Remove LpDacMode option. This is always over-ride by LpDacSW. For Silicon 1, LPDAC mode is set to normal mode.
*Remove ADCFILTERCON bit[18:16] which should be reserved as value zero. Existing examples are updated to remove related code.

### Fixed
* Fixed bug in SPI_Master and SPI_SLAVE examples
* Fix bug in ADuCM355Port.c

## 0.1.0(2020-2-21)

* Initial release of project