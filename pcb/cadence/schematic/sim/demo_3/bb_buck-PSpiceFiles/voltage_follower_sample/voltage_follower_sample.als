.ALIASES
M_M1            M1(d=N00136 g=N13377 s=N00143 s=N00143 ) CN
+@BB_BUCK.voltage_follower_sample(sch_1):INS28@PWRMOS.IRF150.Normal(chips)
V_V1            V1(+=N00136 -=0 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS55@SOURCE.VDC.Normal(chips)
V_V2            V2(+=N13377 -=N00143 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS92@SOURCE.VPULSE.Normal(chips)
C_C1            C1(1=0 2=OUT ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS222@ANALOG.C.Normal(chips)
R_R1            R1(1=0 2=N00181 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS247@ANALOG.R.Normal(chips)
D_D1            D1(1=0 2=N00143 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS486@DIODE.D1N5818.Normal(chips)
R_R2            R2(1=OUT 2=N00181 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS1526@ANALOG.R.Normal(chips)
R_R3            R3(1=N02079 2=OUT ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS1939@ANALOG.R.Normal(chips)
R_R4            R4(1=N02079 2=0 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS1955@ANALOG.R.Normal(chips)
R_R5            R5(1=N00181 2=N02066 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS1971@ANALOG.R.Normal(chips)
R_R6            R6(1=N02066 2=0 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS1987@ANALOG.R.Normal(chips)
V_V3            V3(+=0 -=VEE ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS2257@SOURCE.VDC.Normal(chips)
V_V4            V4(+=VCC -=0 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS2277@SOURCE.VDC.Normal(chips)
M_M2            M2(d=N00136 g=N13287 s=N00143 s=N00143 ) CN
+@BB_BUCK.voltage_follower_sample(sch_1):INS12586@PWRMOS.IRF150.Normal(chips)
M_M3            M3(d=N00136 g=N14575 s=N00143 s=N00143 ) CN
+@BB_BUCK.voltage_follower_sample(sch_1):INS12610@PWRMOS.IRF150.Normal(chips)
V_V5            V5(+=N13287 -=N00143 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS12932@SOURCE.VPULSE.Normal(chips)
V_V6            V6(+=N14575 -=N00143 ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS14527@SOURCE.VPULSE.Normal(chips)
L_L2            L2(1=N00143 2=OUT ) CN @BB_BUCK.voltage_follower_sample(sch_1):INS14693@ANALOG.L.Normal(chips)
X_U3A           U3A(+=N02079 -=AD_I+ V+=VCC V-=VEE OUT=AD_I+ ) CN
+@BB_BUCK.voltage_follower_sample(sch_1):INS18829@ON_AMP.LM358/ON.Normal(chips)
X_U3B           U3B(+=N02066 -=AD_I- V+=VCC V-=VEE OUT=AD_I- ) CN
+@BB_BUCK.voltage_follower_sample(sch_1):INS18878@ON_AMP.LM358/ON.Normal(chips)
_    _(AD_I+=AD_I+)
_    _(AD_I-=AD_I-)
_    _(out=OUT)
_    _(VCC=VCC)
_    _(VEE=VEE)
.ENDALIASES
