 ;7800basic v0.24 Mar  2 2023 18:16:27
SPACEOVERFLOW SET 0
game
.L00 ;;  set tallsprite on

.L01 ;;  set zoneheight 8

.L02 ;;  displaymode 320A

    lda #%01000011 ;Enable DMA, mode=160x2/160x4
    sta CTRL

    sta sCTRL

.
 ;; 

.
 ;; 

.L03 ;;  P1C2  =  $46

	LDA #$46
	STA P1C2
.L04 ;;  P2C2  =  $AA

	LDA #$AA
	STA P2C2
.L05 ;;  P3C2  =  $0F

	LDA #$0F
	STA P3C2
.
 ;; 

.L06 ;;  incgraphic dhero.png 320C 0 1 2 3

.
 ;; 

.Main
 ;; Main

.L07 ;;  clearscreen

 jsr clearscreen
.L08 ;;  plotsprite dhero 0 72 64

    lda #<dhero
    sta temp1

    lda #>dhero
    sta temp2

    lda #(0|dhero_width_twoscompliment)
    sta temp3

    lda #72
    sta temp4

    lda #64

    sta temp5

    lda #(dhero_mode|%01000000)
    sta temp6

 jsr plotsprite
    ; +tall sprite replot
    clc
    lda temp1
    adc #dhero_width
    sta temp1
    lda temp5
    adc #WZONEHEIGHT
    sta temp5
    jsr plotsprite
    ; +tall sprite replot
    clc
    lda temp1
    adc #dhero_width
    sta temp1
    lda temp5
    adc #WZONEHEIGHT
    sta temp5
    jsr plotsprite
    ; +tall sprite replot
    clc
    lda temp1
    adc #dhero_width
    sta temp1
    lda temp5
    adc #WZONEHEIGHT
    sta temp5
    jsr plotsprite
.L09 ;;  drawscreen

 jsr drawscreen
.L010 ;;  goto Main

 jmp .Main

.L011 ;;  
DMAHOLEEND0 SET .
gameend
DMAHOLEEND0 SET .
 echo " ",[($E000 - gameend)]d , "bytes of ROM space left in the main area."
 if ($E000 - gameend) < 0
SPACEOVERFLOW SET (SPACEOVERFLOW+1)
 endif
 if START_OF_ROM = . ; avoid dasm empty start-rom truncation.
     .byte 0
 endif
START_OF_ROM SET 0 ; scuttle so we always fail subsequent banks

 ORG $E000,0  ; *************

dhero = $E000

dhero
       HEX fa75fad9f5f51288
dhero_tallsprite_00 = $E008

dhero_tallsprite_00
       HEX 1275eaffff000000
dhero_tallsprite_01 = $E010

dhero_tallsprite_01
       HEX 0033cc000033cc00
dhero_tallsprite_02 = $E018

dhero_tallsprite_02
       HEX 0000000000000000

 ORG $E100,0  ; *************

;dhero
       HEX fafafad9f5e51288
;dhero_tallsprite_00
       HEX 32f6fa75e5001288
;dhero_tallsprite_01
       HEX 0033cc000033cc00
;dhero_tallsprite_02
       HEX 0000000000000000

 ORG $E200,0  ; *************

;dhero
       HEX 0000000000001288
;dhero_tallsprite_00
       HEX 7ae5fab9e5001288
;dhero_tallsprite_01
       HEX 0013ef00007f8c00
;dhero_tallsprite_02
       HEX 0000000000000000

 ORG $E300,0  ; *************

;dhero
       HEX 000000ffcc001288
;dhero_tallsprite_00
       HEX faf9fad9e50075c4
;dhero_tallsprite_01
       HEX 0013ff0000ff8c00
;dhero_tallsprite_02
       HEX 0000000000000000

 ORG $E400,0  ; *************

;dhero
       HEX 000000ffcc001288
;dhero_tallsprite_00
       HEX faf9b6d9f500f5e5
;dhero_tallsprite_01
       HEX 0000ffcc33ff0000
;dhero_tallsprite_02
       HEX 11f5c4000031f584

 ORG $E500,0  ; *************

;dhero
       HEX 000000ffcc001288
;dhero_tallsprite_00
       HEX fafaf6d9f5959688
;dhero_tallsprite_01
       HEX 00327fffffef0000
;dhero_tallsprite_02
       HEX 11f5c4000031f584

 ORG $E600,0  ; *************

;dhero
       HEX 000000ffcc001288
;dhero_tallsprite_00
       HEX fafaf6d9f5959688
;dhero_tallsprite_01
       HEX 007abbffffcc0000
;dhero_tallsprite_02
       HEX 00f5c4000031f500

 ORG $E700,0  ; *************

;dhero
       HEX 0000007f8c000000
;dhero_tallsprite_00
       HEX faf5b6d9f5b51288
;dhero_tallsprite_01
       HEX 00f9dbffff8c0000
;dhero_tallsprite_02
       HEX 0031c4000031c400
 if SPACEOVERFLOW > 0
 echo ""
 echo "######## ERROR: space overflow detected in",[SPACEOVERFLOW]d,"areas."
 echo "######## look above for areas with negative ROM space left."
 echo "######## Aborting assembly."
 ERR
 endif
 

