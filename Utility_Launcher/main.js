const { app, BrowserWindow,Menu} = require('electron')
const{shell}=require('electron').shell
const path = require('path');
const { electron } = require('process');
let win=null;
 createWindow = () => {
  win=new BrowserWindow({
        width:600,
        height:600
    });
    win.loadFile("Window.html");
    }

    const mainMenuTemplate =
    [{
        label:'File',
        submenu:
        [{
            label:'Note Pad',
            click:function()
    {
      
var child = require('child_process').execFile
var executablePath = "C:\\Windows\\system32\\notepad.exe"

child(executablePath, function(err, data) {
    if(err){
       console.error(err);
       return;
    }
 
    console.log(data.toString());
});

    }
            
        },
        {
            type:'separator'
        },
       {
        label:'Microsoft Word',

        click:function()
    {
      
var child = require('child_process').execFile
var executablePath = "C:\\Program Files (x86)\\Microsoft Office\\Office14\\WINWORD.EXE"

child(executablePath, function(err, data) {
    if(err){
       console.error(err);
       return;
    }
 
    console.log(data.toString());
});

    }

       },
      {
        type:'separator'
      },
     {
        label:'Microsoft Paint',
        click:function()
        {
          
    var child = require('child_process').execFile
    var executablePath = "C:\\Windows\\system32\\mspaint.exe"
    
    child(executablePath, function(err, data) {
        if(err){
           console.error(err);
           return;
        }
     
        console.log(data.toString());
    });
    
        }
     }
     ]
    },
{
    label:'Help',
    click:function()

    {
        require('electron').shell.openExternal("https://www.electronjs.org/");
    }
    
   
}]   
const menu=Menu.buildFromTemplate(mainMenuTemplate)   
Menu.setApplicationMenu(menu)
app.whenReady().then(createWindow);


