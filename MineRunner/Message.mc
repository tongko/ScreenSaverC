;#pragma once
;

MessageIdTypedef = DWORD

SeverityNames=
	(
		Success			= 0x0:STATUS_SEVERITY_SUCCESS
		Informational	= 0x1:STATUS_SEVERITY_INFORMATIONAL
		Warning			= 0x2:STATUS_SEVERITY_WARNING
		Error			= 0x3:STATUS_SEVERITY_ERROR
	)

FacilityNames =
	(
		System	=0x0:FACILITY_SYSTEM
		Runtime	=0x2:FACILITY_RUNTIME
		Stubs	=0x3:FACILITY_STUBS
		Io		=0x4:FACILITY_IO_ERROR_CODE
	)

LanguageNames = 
	(
		English = 0x0409:MSG_EN
		Chinese = 0x0804:MSG_ZH
	)

MessageId		= 1
SymbolicName	= MSG_SUCCESS
Severity		= Success
Language        = English
Success
.
Language		= Chinese
成功
.

MessageId		= +1
SymbolicName	= MSG_OUT_OF_MEM
Language		= English
Out of memory
.
Language		= Chinese
内存不足
.
