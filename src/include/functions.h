/*
// Full copyright information is available in the file ../doc/CREDITS
*/

#ifndef cdc_functions_h
#define cdc_functions_h

#include "macros.h"

COLDC_FUNC(anticipate_assignment);
COLDC_FUNC(buflen);
COLDC_FUNC(bufidx);
COLDC_FUNC(bufgraft);
COLDC_FUNC(buf_replace);
COLDC_FUNC(subbuf);
COLDC_FUNC(buf_to_str);
COLDC_FUNC(buf_to_strings);
COLDC_FUNC(str_to_buf);
COLDC_FUNC(strings_to_buf);
COLDC_FUNC(size);
COLDC_FUNC(type);
COLDC_FUNC(frob_class);
COLDC_FUNC(frob_value);
COLDC_FUNC(frob_handler);
COLDC_FUNC(toint);
COLDC_FUNC(tofloat);
COLDC_FUNC(tostr);
COLDC_FUNC(toliteral);
COLDC_FUNC(fromliteral);
COLDC_FUNC(toobjnum);
COLDC_FUNC(tosym);
COLDC_FUNC(toerr);
COLDC_FUNC(valid);
COLDC_FUNC(dict_values);
COLDC_FUNC(dict_keys);
COLDC_FUNC(dict_add);
COLDC_FUNC(dict_del);
COLDC_FUNC(dict_contains);
COLDC_FUNC(dict_union);
COLDC_FUNC(error);
COLDC_FUNC(traceback);
COLDC_FUNC(throw);
COLDC_FUNC(rethrow);
COLDC_FUNC(fopen);
COLDC_FUNC(file);
COLDC_FUNC(files);
COLDC_FUNC(fclose);
COLDC_FUNC(fchmod);
COLDC_FUNC(frmdir);
COLDC_FUNC(fmkdir);
COLDC_FUNC(fremove);
COLDC_FUNC(fseek);
COLDC_FUNC(frename);
COLDC_FUNC(fflush);
COLDC_FUNC(feof);
COLDC_FUNC(fread);
COLDC_FUNC(fwrite);
COLDC_FUNC(fstat);
COLDC_FUNC(execute);
COLDC_FUNC(listlen);
COLDC_FUNC(listgraft);
COLDC_FUNC(sublist);
COLDC_FUNC(insert);
COLDC_FUNC(join);
COLDC_FUNC(listidx);
COLDC_FUNC(replace);
COLDC_FUNC(delete);
COLDC_FUNC(setadd);
COLDC_FUNC(setremove);
COLDC_FUNC(union);
COLDC_FUNC(join);
COLDC_FUNC(random);
COLDC_FUNC(max);
COLDC_FUNC(min);
COLDC_FUNC(abs);
COLDC_FUNC(time);
COLDC_FUNC(localtime);
COLDC_FUNC(mtime);
COLDC_FUNC(ctime);
COLDC_FUNC(bind_function);
COLDC_FUNC(unbind_function);
COLDC_FUNC(debug_callers);
COLDC_FUNC(call_trace);
COLDC_FUNC(reassign_connection);
COLDC_FUNC(bind_port);
COLDC_FUNC(unbind_port);
COLDC_FUNC(open_connection);
COLDC_FUNC(close_connection);
COLDC_FUNC(cwrite);
COLDC_FUNC(cwritef);
COLDC_FUNC(connection);
COLDC_FUNC(add_var);
COLDC_FUNC(del_var);
COLDC_FUNC(variables);
COLDC_FUNC(set_var);
COLDC_FUNC(get_var);
COLDC_FUNC(default_var);
COLDC_FUNC(inherited_var);
COLDC_FUNC(clear_var);
COLDC_FUNC(add_method);
COLDC_FUNC(rename_method);
COLDC_FUNC(method_flags);
COLDC_FUNC(set_method_flags);
COLDC_FUNC(method_access);
COLDC_FUNC(set_method_access);
COLDC_FUNC(method_info);
COLDC_FUNC(methods);
COLDC_FUNC(find_method);
COLDC_FUNC(find_next_method);
COLDC_FUNC(list_method);
COLDC_FUNC(method_bytecode);
COLDC_FUNC(del_method);
COLDC_FUNC(parents);
COLDC_FUNC(children);
COLDC_FUNC(ancestors);
COLDC_FUNC(has_ancestor);
COLDC_FUNC(create);
COLDC_FUNC(chparents);
COLDC_FUNC(destroy);
COLDC_FUNC(data);
COLDC_FUNC(set_objname);
COLDC_FUNC(del_objname);
COLDC_FUNC(objname);
COLDC_FUNC(lookup);
COLDC_FUNC(objnum);
COLDC_FUNC(strlen);
COLDC_FUNC(strgraft);
COLDC_FUNC(stridx);
COLDC_FUNC(substr);
COLDC_FUNC(explode);
COLDC_FUNC(strsub);
COLDC_FUNC(strsed);
COLDC_FUNC(pad);
COLDC_FUNC(match_begin);
COLDC_FUNC(match_template);
COLDC_FUNC(match_pattern);
COLDC_FUNC(match_regexp);
COLDC_FUNC(regexp);
COLDC_FUNC(split);
COLDC_FUNC(crypt);
COLDC_FUNC(match_crypted);
COLDC_FUNC(uppercase);
COLDC_FUNC(lowercase);
COLDC_FUNC(strcmp);
COLDC_FUNC(strfmt);
COLDC_FUNC(dblog);
COLDC_FUNC(backup);
COLDC_FUNC(shutdown);
COLDC_FUNC(set_heartbeat);
COLDC_FUNC(cache_info);
COLDC_FUNC(cancel);
COLDC_FUNC(suspend);
COLDC_FUNC(resume);
COLDC_FUNC(pause);
COLDC_FUNC(atomic);
COLDC_FUNC(refresh);
COLDC_FUNC(tasks);
COLDC_FUNC(tick);
COLDC_FUNC(stack);
COLDC_FUNC(calling_method);
COLDC_FUNC(method);
COLDC_FUNC(this);
COLDC_FUNC(definer);
COLDC_FUNC(sender);
COLDC_FUNC(caller);
COLDC_FUNC(user);
COLDC_FUNC(set_user);
COLDC_FUNC(task_id);
COLDC_FUNC(task_info);
COLDC_FUNC(ticks_left);
COLDC_FUNC(sin);
COLDC_FUNC(exp);
COLDC_FUNC(log);
COLDC_FUNC(cos);
COLDC_FUNC(tan);
COLDC_FUNC(sqrt);
COLDC_FUNC(asin);
COLDC_FUNC(acos);
COLDC_FUNC(atan);
COLDC_FUNC(pow);
COLDC_FUNC(atan2);
COLDC_FUNC(round);
COLDC_FUNC(config);

#endif
