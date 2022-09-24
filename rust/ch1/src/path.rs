use std::io;
use std::{fs, path::PathBuf};
pub struct pathmgr {
    base_path: PathBuf,
}

struct FileInfo {}

impl pathmgr {
    pub fn get_sub_files(&self) -> io::Result<Vec<PathBuf>> {
        let mut results: Vec<PathBuf> = Vec::new();
        for entry in fs::read_dir(self.base_path.to_str().unwrap())? {
            let entry = entry?;
            let data = entry.metadata()?;
            let path = entry.path();
            if data.is_file() {
                results.push(path);
            }
        }
        Ok(results)
    }

    pub fn new(_path: String) -> Result<pathmgr, io::Error> {
        let path = PathBuf::from(_path);
        let abs_path = fs::canonicalize(&path);
        match abs_path {
            Ok(v) => {
                return Ok(pathmgr { base_path: v });
            }
            Err(e) => return Err(e),
        };
    }
}
