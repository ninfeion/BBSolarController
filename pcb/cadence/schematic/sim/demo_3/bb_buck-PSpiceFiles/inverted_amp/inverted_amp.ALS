.ALIASES
R_R2            R2(1=N00265 2=N00248 ) CN @BB_BUCK.inverted_amp(sch_1):INS109@ANALOG.R.Normal(chips)
R_R1            R1(1=N00248 2=OUT ) CN @BB_BUCK.inverted_amp(sch_1):INS93@ANALOG.R.Normal(chips)
V_V3            V3(+=N00265 -=0 ) CN @BB_BUCK.inverted_amp(sch_1):INS298@SOURCE.VDC.Normal(chips)
V_V2            V2(+=0 -=N00170 ) CN @BB_BUCK.inverted_amp(sch_1):INS150@SOURCE.VDC.Normal(chips)
V_V1            V1(+=N00182 -=0 ) CN @BB_BUCK.inverted_amp(sch_1):INS134@SOURCE.VDC.Normal(chips)
X_U1            U1(+=N00523 -=N00248 V+=N00182 V-=N00170 OUT=OUT ) CN
+@BB_BUCK.inverted_amp(sch_1):INS46@ANLG_DEV.AD8072jn/AD.Normal(chips)
R_R3            R3(1=0 2=N00523 ) CN @BB_BUCK.inverted_amp(sch_1):INS426@ANALOG.R.Normal(chips)
R_R4            R4(1=0 2=N00523 ) CN @BB_BUCK.inverted_amp(sch_1):INS446@ANALOG.R.Normal(chips)
_    _(out=OUT)
.ENDALIASES
