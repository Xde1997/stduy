var fs=require("fs");
var path=require("path");
function CountLine(path)
{
    let data=fs.readFileSync(path, 'UTF-8')
    let lines=data.split(/\r?\n/);
    
    return lines.filter(function(item){
        if(item=="")
        {
            return false
        }
        return true
    }).length
}

function GetAllPath(_path,out)
{
    try{
        let files=fs.readdirSync(_path);
        files.forEach(function(item){
            let tempPath=path.join(_path,item)
            let stats=fs.statSync(tempPath)
            if(stats.isDirectory())
            {
                GetAllPath(tempPath,out)
            }
            else
            {
                let extname= path.extname(item).replace(".","")
                if(extname=="go"||extname=="cpp"||extname=="h"||extname=="py"||extname=="java")
                {
                    out.push(tempPath)
                }
            }
        })
    }catch(e)
    {
        console.log("Path Error:"+_path)
    }
    return out
}

//判断字符是否为空的方法
function isEmpty(obj){
    if(typeof obj == "undefined" || obj == null || obj == ""){
        return true
    }else{
       return false
    }
}

let rootpath=__dirname
if(!isEmpty(process.argv[2]))
{
    rootpath=process.argv[2]
}
let files=[]
GetAllPath(rootpath,files)
let lineCount=0;
files.forEach(function(item){
    lineCount+=CountLine(item)
})
console.log("Files In Folder is "+lineCount+" line!")
