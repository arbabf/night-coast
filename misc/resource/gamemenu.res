// Made with XBLAH's Modding tool.
// Download it at https://github.com/jean-knapp/windows-source-modding-tool/releases

"gamemenu"
{
	"0"
	{
		"label"	"RESUME GAME"
		"command"	"ResumeGame"
		"ingameorder"	"0"
		"onlyingame"	"1"
	}
	"1"
	{
		"label"	"NEW GAME"
		"command"	"OpenNewGameDialog"
		"ingameorder"	"1"
		"nomulti"	"1"
	}
	"2"
	{
		"label"	"LOAD GAME"
		"command"	"OpenLoadGameDialog"
		"ingameorder"	"2"
		"nomulti"	"1"
	}
	"3"
	{
		"label"	"SAVE GAME"
		"command"	"OpenSaveGameDialog"
		"ingameorder"	"3"
		"onlyingame"	"1"
		"nomulti"	"1"
	}
	"4"
	{
		"label"	"OPTIONS"
		"command"	"OpenOptionsDialog"
		"ingameorder"	"4"
	}
	"5"
	{
		"label"	"QUIT"
		"command"	"Quit"
		"ingameorder"	"5"
	}
}
