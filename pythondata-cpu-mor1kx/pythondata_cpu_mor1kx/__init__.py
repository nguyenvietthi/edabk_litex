import os.path
__dir__ = os.path.split(os.path.abspath(os.path.realpath(__file__)))[0]
data_location = os.path.join(__dir__, "verilog")
src = "https://github.com/openrisc/mor1kx.git"

# Module version
version_str = "5.1.post130"
version_tuple = (5, 1, 130)
try:
    from packaging.version import Version as V
    pversion = V("5.1.post130")
except ImportError:
    pass

# Data version info
data_version_str = "5.1.post4"
data_version_tuple = (5, 1, 4)
try:
    from packaging.version import Version as V
    pdata_version = V("5.1.post4")
except ImportError:
    pass
data_git_hash = "44ea6983674072feed48ece06009acb9e86eb05c"
data_git_describe = "v5.1-4-g44ea698"
data_git_msg = """\
commit 44ea6983674072feed48ece06009acb9e86eb05c
Merge: aca2481 6b1beaa
Author: Stafford Horne <shorne@gmail.com>
Date:   Sun Feb 27 06:18:13 2022 +0900

    Merge pull request #148 from openrisc/fpcsr_free_access
    
    Make FPCSR is R/W accessible for both user- and supervisor- modes.

"""

# Tool version info
tool_version_str = "0.0.post126"
tool_version_tuple = (0, 0, 126)
try:
    from packaging.version import Version as V
    ptool_version = V("0.0.post126")
except ImportError:
    pass


def data_file(f):
    """Get absolute path for file inside pythondata_cpu_mor1kx."""
    fn = os.path.join(data_location, f)
    fn = os.path.abspath(fn)
    if not os.path.exists(fn):
        raise IOError("File {f} doesn't exist in pythondata_cpu_mor1kx".format(f))
    return fn
