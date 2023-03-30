impl Solution {
    pub fn simplify_path(path: String) -> String {
        let names: Vec<&str> = path.split('/').collect();
        let mut result = Vec::new();
        for name in names {
            if name == "." {
                // pass
            } else if name == ".." {
                if !result.is_empty() {
                    result.pop();
                }
            } else if name != "" {
                result.push(name);
            }
        }
        let mut s = String::new();
        if !result.is_empty() {
            for r in result {
                s = format!("{}{}{}", s, "/", r);
            }
        } else {
            s = "/".to_string();
        }
        return s;
    }
}
