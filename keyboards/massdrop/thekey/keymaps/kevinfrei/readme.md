# The Key

3 key macro pad mapping

I want 6 modes, plus a "turn the light off" capability

My Layer ID's are thus:

- `MED` : Media
- `VS` : Visual Studio Code debugging
- `IJ` : IntelliJ (& Android Studio) debugging
- `PAT` : RGB Pattern/Mode switching
- `SPD` : RGB Effect Speed adjustment
- `BR` : RGB Brightness adjustment

| Layer | StackOverflow                        | C                         | V                          |
| ----- | ------------------------------------ | ------------------------- | -------------------------- |
| `MED` | Mute: `KC_MUTE`                      | Play/Pause: `KC_MPLY`     | Next Track: `KC_MNXT`      |
| `VS`  | Step Out [Shift-F11]: `LSFT(KC_F11)` | Step Over [F10]: `KC_F10` | Step In [F11]: `KC_F11`    |
| `IJ`  | Step Out [Shift-F8]: `LSFT(KC_F8)`   | Step Over [F8]: `KC_F8`   | Step In [F7]: `KC_F7`      |
| `PAT` | RGB Mode - (`RGB_RMOD`)              |                           | RGB Mode + (`RGB_MOD`)     |
| `SPD` | Effect Speed - (`RGB_SPD`)           |                           | Effect Speed + (`RGB_SPI`) |
| `BR`  | Brightness - (`RGB_BRD`)             |                           | Brightness + (`RGB_BRI`)   |

To accomplish this, I need to use the `LT(#, keystroke)` QMK capability
aggressively (Layer/Tap). This lets a 'tap' be `keystroke` while a 'hold' is
shifting to layer `#`. This means I need some "Mode Select" layers. The
challenge, however, is that QMK doesn't support anything "fancy" in those
`keystroke` slots, not even a "hold shift down while tapping a key" (`LSFT()`).
The `TG(layer)` function toggles the `layer` on or off. With that in mind,
here's what I want to be able to "get to" each layer:

| Layer | SO                 | C                  | V                 |
| ----- | ------------------ | ------------------ | ----------------- |
| `MED` | `LT(DBG, KC_MUTE)` | `LT(MSP, KC_MPLY)` | `LT(BT, KC_NXTT)` |
| `DBG` | `KC_TRNS`          | `MO(VS)`           | `MO(IJ)`          |
| `MSP` | `MO(PAT)`          | `KC_TRNS`          | `MO(SPD)`         |
| `BT`  | `MO(BR)`           | `RGB_TOG`          | `KC_TRNS`         |
| `VS`  | `LSFT(KC_F11)`     | `KC_F10`           | `KC_F11`          |
| `IJ`  | `LSFT(KC_F8)`      | `KC_F8`            | `KC_F7`           |
| `PAT` | `RGB_RMOD`         |                    | `RGB_MOD`         |
| `SPD` | `RGB_SPD`          |                    | `RGB_SPI`         |
| `BR`  | `RGB_BRD`          |                    | `RGB_BRI`         |

Now, if you're playing along, you'll notice that I have no way "out" of those
various modes back to normal. For the RGB specific ones, it's easy thanks to
those empty spots. But for the VSCode and IntelliJ modes, it's a little messier.
I can use some more `LT(...)` magic, but we have to apply it carefully, because
I can't use it on the SO key bindings for those two modes, because they use an
`LSFT()`. So I map the C-key to use the `LT()` feature and go to another layer
that then allows either of the two other keys to be used to go back to the
normal Media mode.

| #     | SO                 | C                  | V                 |
| ----- | ------------------ | ------------------ | ----------------- |
| `MED` | `LT(DBG, KC_MUTE)` | `LT(MSP, KC_MPLY)` | `LT(BT, KC_NXTT)` |
| `DBG` | `KC_TRNS`          | `TG(VS)`           | `TG(IJ)`          |
| `MSP` | `TG(PAT)`          | `KC_TRNS`          | `TG(SPD)`         |
| `BT`  | `TG(BR)`           | `RGB_TOG`          | `KC_TRNS`         |
| `VS`  | `LSFT(KC_F11)`     | `LT(VSO, KC_F10)`  | `KC_F11`          |
| `IJ`  | `LSFT(KC_F8)`      | `LT(IJO, KC_F8)`   | `KC_F7`           |
| `PAT` | `RGB_RMOD`         | `TG(PAT)`          | `RGB_MOD`         |
| `SPD` | `RGB_SPD`          | `TG(SPD)`          | `RGB_SPI`         |
| `BR`  | `RGB_BRD`          | `TG(BR)`           | `RGB_BRI`         |
| `VSO` | `TG(VS)`           | `KC_TRNS`          | `TG(VS)`          |
| `IJO` | `TG(IJ)`           | `KC_TRNS`          | `TG(IJ)`          |

So, now we have a way of getting out of the VSCode and IntelliJ modes: Hold the
middle button down, and hit either of the other two buttons. That should
"toggle" the VS/IJ layers, returning us back to `MED`.

Maybe I'll draw a little state machine graph some time, because that's what this
is, but for now, this was just me writing up my thought process. I'm going to go
try it out, now!

## Notes

The LED's are ordered:

- 0: right most edge light
- 1: left most edge light
- 2: StackOverflow key
- 3: Copy key
- 4: Paste key
