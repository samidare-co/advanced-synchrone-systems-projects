/* --- Generated the 10/12/2024 at 12:26 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 27 23:48:47 CET 2024) --- */
/* --- Command line: /home/sami/.opam/default/bin/heptc -target c scheduler.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scheduler.h"

void Scheduler__slp_aux_step(Scheduler_data__select_acc sa, int proc,
                             Scheduler_data__aux_type acc,
                             Scheduler__slp_aux_out* _out) {
  
  Scheduler_data__aux_type v_1;
  int v;
  v = (acc.sel_period<sa.speriod);
  v_1.sel_proc = proc;
  v_1.sel_period = sa.speriod;
  if (v) {
    _out->o = v_1;
  } else {
    _out->o = acc;
  };;
}

void Scheduler__select_largest_period_step(Scheduler_data__select_acc acc[2],
                                           Scheduler__select_largest_period_out* _out) {
  Scheduler__slp_aux_out Scheduler__slp_aux_out_st;
  
  Scheduler_data__aux_type v_2;
  Scheduler_data__select_acc v;
  Scheduler_data__aux_type search_result;
  v = acc[0];
  v_2.sel_proc = 0;
  v_2.sel_period = v.speriod;
  search_result = v_2;
  {
    int i;
    for (i = 0; i < Scheduler_data__nproc; ++i) {
      Scheduler__slp_aux_step(acc[i], i, search_result,
                              &Scheduler__slp_aux_out_st);
      search_result = Scheduler__slp_aux_out_st.o;
    }
  };
  _out->lp = search_result.sel_proc;;
}

void Scheduler__update_proc_step(int i, int select_task,
                                 Scheduler_data__task_status ts,
                                 int select_tp,
                                 Scheduler__update_proc_out* _out) {
  
  int v_4;
  int v_3;
  int v;
  v_3 = (ts.current_proc==i);
  v = (ts.status==Scheduler_data__Running);
  v_4 = (v&&v_3);
  if (v_4) {
    _out->o = select_task;
  } else {
    _out->o = select_tp;
  };;
}

void Scheduler__proc_task_step(Scheduler_data__task_status ts, int t_index,
                               int tp_acc[2], Scheduler__proc_task_out* _out) {
  
  int v_5[2];
  int v;
  v = (ts.status==Scheduler_data__Running);
  {
    int _1;
    for (_1 = 0; _1 < 2; ++_1) {
      v_5[_1] = tp_acc[_1];
    }
  };
  if (((ts.current_proc<Scheduler_data__nproc)&&(0<=ts.current_proc))) {
    v_5[ts.current_proc] = t_index;
  };
  if (v) {
    {
      int _2;
      for (_2 = 0; _2 < 2; ++_2) {
        _out->o[_2] = v_5[_2];
      }
    };
  } else {
    {
      int _3;
      for (_3 = 0; _3 < 2; ++_3) {
        _out->o[_3] = tp_acc[_3];
      }
    };
  };;
}

void Scheduler__extract_proc_step(Scheduler_data__task_status ts[2],
                                  Scheduler__extract_proc_out* _out) {
  Scheduler__proc_task_out Scheduler__proc_task_out_st;
  
  int init_proc[2];
  {
    int _4;
    for (_4 = 0; _4 < Scheduler_data__nproc; ++_4) {
      init_proc[_4] = 2;
    }
  };
  {
    int _5;
    for (_5 = 0; _5 < 2; ++_5) {
      _out->o[_5] = init_proc[_5];
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler_data__ntasks; ++i) {
      Scheduler__proc_task_step(ts[i], i, _out->o,
                                &Scheduler__proc_task_out_st);
      {
        int _6;
        for (_6 = 0; _6 < 2; ++_6) {
          _out->o[_6] = Scheduler__proc_task_out_st.o[_6];
        }
      };
    }
  };;
}

void Scheduler__complete_step(Scheduler_data__task_status tasks_map,
                              int task_end, Scheduler__complete_out* _out) {
  
  Scheduler_data__task_status v_8;
  Scheduler_data__task_status v_7;
  Scheduler_data__task_status v_6;
  int v;
  v = (tasks_map.status==Scheduler_data__Running);
  v_7.status = Scheduler_data__Ready;
  v_7.current_proc = tasks_map.current_proc;
  v_7.current_deadline = tasks_map.current_deadline;
  v_6 = tasks_map;
  v_6.status = Scheduler_data__Waiting;
  if (task_end) {
    v_8 = v_6;
  } else {
    v_8 = v_7;
  };
  if (v) {
    _out->o = v_8;
  } else {
    _out->o = tasks_map;
  };;
}

void Scheduler__check_deadline_step(int current_date,
                                    Scheduler_data__task_status tsi, int tid,
                                    Scheduler__check_deadline_out* _out) {
  Externc__deadline_miss_log_out Externc__deadline_miss_log_out_st;
  
  Scheduler_data__task_status v_10;
  int v_9;
  int v;
  int c;
  v_9 = (tsi.current_deadline==current_date);
  v = (tsi.status==Scheduler_data__Ready);
  c = (v&&v_9);
  if (c) {
    Externc__deadline_miss_log_step(current_date, tid,
                                    &Externc__deadline_miss_log_out_st);
  };
  v_10 = tsi;
  v_10.status = Scheduler_data__Waiting;
  if (c) {
    _out->tso = v_10;
  } else {
    _out->tso = tsi;
  };;
}

void Scheduler__start_inst_step(int current_date,
                                Scheduler_data__task_status tsi,
                                Scheduler_data__task_attributes ta,
                                Scheduler__start_inst_out* _out) {
  
  Scheduler_data__task_status v_13;
  int v_12;
  int v_11;
  int v;
  int c;
  v = (current_date-ta.first_start);
  v_11 = (v%ta.period);
  c = (v_11==0);
  if (c) {
    v_12 = (current_date+ta.deadline);
    v_13.status = Scheduler_data__Ready;
    v_13.current_proc = tsi.current_proc;
    v_13.current_deadline = v_12;
    _out->tso = v_13;
  } else {
    _out->tso = tsi;
  };;
}

void Scheduler__select_aux_step(Scheduler_data__task_status ts,
                                Scheduler_data__task_attributes ta, int tid,
                                Scheduler_data__select_acc acc[2],
                                Scheduler__select_aux_out* _out) {
  Scheduler__select_largest_period_out Scheduler__select_largest_period_out_st;
  
  Scheduler_data__select_acc v_17[2];
  Scheduler_data__select_acc v_16[2];
  Scheduler_data__select_acc v_15;
  int v_14;
  int v;
  int lp;
  v = (ts.status==Scheduler_data__Ready);
  Scheduler__select_largest_period_step(acc,
                                        &Scheduler__select_largest_period_out_st);
  lp = Scheduler__select_largest_period_out_st.lp;
  v_14 = (ta.period<lp);
  v_15.tid = tid;
  v_15.speriod = ta.period;
  {
    int _7;
    for (_7 = 0; _7 < 2; ++_7) {
      v_16[_7] = acc[_7];
    }
  };
  if (((lp<Scheduler_data__nproc)&&(0<=lp))) {
    v_16[lp] = v_15;
  };
  if (v_14) {
    {
      int _8;
      for (_8 = 0; _8 < 2; ++_8) {
        v_17[_8] = v_16[_8];
      }
    };
  } else {
    {
      int _9;
      for (_9 = 0; _9 < 2; ++_9) {
        v_17[_9] = acc[_9];
      }
    };
  };
  if (v) {
    {
      int _10;
      for (_10 = 0; _10 < 2; ++_10) {
        _out->acc_o[_10] = v_17[_10];
      }
    };
  } else {
    {
      int _11;
      for (_11 = 0; _11 < 2; ++_11) {
        _out->acc_o[_11] = acc[_11];
      }
    };
  };;
}

void Scheduler__select_tid_step(Scheduler_data__select_acc s,
                                Scheduler__select_tid_out* _out) {
  _out->o = s.tid;
}

void Scheduler__select_tasks_step(Scheduler_data__task_status ts[2],
                                  Scheduler__select_tasks_out* _out) {
  Scheduler__select_tid_out Scheduler__select_tid_out_st;
  Scheduler__select_aux_out Scheduler__select_aux_out_st;
  
  Scheduler_data__select_acc v[2];
  Scheduler_data__select_acc tmp[2];
  {
    int _12;
    for (_12 = 0; _12 < Scheduler_data__nproc; ++_12) {
      v[_12].speriod = 1000;
      v[_12].tid = 2;
    }
  };
  {
    int _13;
    for (_13 = 0; _13 < 2; ++_13) {
      tmp[_13] = v[_13];
    }
  };
  {
    int i_8;
    for (i_8 = 0; i_8 < Scheduler_data__ntasks; ++i_8) {
      Scheduler__select_aux_step(ts[i_8], Scheduler_data__tasks[i_8], i_8,
                                 tmp, &Scheduler__select_aux_out_st);
      {
        int _14;
        for (_14 = 0; _14 < 2; ++_14) {
          tmp[_14] = Scheduler__select_aux_out_st.acc_o[_14];
        }
      };
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler_data__nproc; ++i) {
      Scheduler__select_tid_step(tmp[i], &Scheduler__select_tid_out_st);
      _out->selected[i] = Scheduler__select_tid_out_st.o;
    }
  };;
}

void Scheduler__update_selected_step(Scheduler_data__task_status ts,
                                     int selected[2], int tid,
                                     Scheduler__update_selected_out* _out) {
  
  Scheduler_data__task_status v_20;
  int v_19;
  int v_18[2];
  int v[2];
  {
    int i_7;
    for (i_7 = 0; i_7 < Scheduler_data__nproc; ++i_7) {
      v[i_7] = tid;
    }
  };
  {
    int i_6;
    for (i_6 = 0; i_6 < Scheduler_data__nproc; ++i_6) {
      v_18[i_6] = (selected[i_6]==v[i_6]);
    }
  };
  v_19 = false;
  {
    int i;
    for (i = 0; i < Scheduler_data__nproc; ++i) {
      v_19 = (v_18[i]||v_19);
    }
  };
  v_20 = ts;
  v_20.status = Scheduler_data__Running;
  if (v_19) {
    _out->tso = v_20;
  } else {
    _out->tso = ts;
  };;
}

void Scheduler__rate_monotonic_mc_step(Scheduler_data__task_status ts[2],
                                       Scheduler__rate_monotonic_mc_out* _out) {
  Scheduler__select_tasks_out Scheduler__select_tasks_out_st;
  Scheduler__update_selected_out Scheduler__update_selected_out_st;
  
  int v[2][2];
  int selected[2];
  Scheduler__select_tasks_step(ts, &Scheduler__select_tasks_out_st);
  {
    int _15;
    for (_15 = 0; _15 < 2; ++_15) {
      selected[_15] = Scheduler__select_tasks_out_st.selected[_15];
    }
  };
  {
    int i_5;
    for (i_5 = 0; i_5 < Scheduler_data__ntasks; ++i_5) {
      {
        int _16;
        for (_16 = 0; _16 < 2; ++_16) {
          v[i_5][_16] = selected[_16];
        }
      };
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler_data__ntasks; ++i) {
      Scheduler__update_selected_step(ts[i], v[i], i,
                                      &Scheduler__update_selected_out_st);
      _out->tso[i] = Scheduler__update_selected_out_st.tso;
    }
  };;
}

void Scheduler__scheduler_reset(Scheduler__scheduler_mem* self) {
  {
    int i_4;
    for (i_4 = 0; i_4 < Scheduler_data__ntasks; ++i_4) {
    }
  };
  {
    int i_1;
    for (i_1 = 0; i_1 < Scheduler_data__ntasks; ++i_1) {
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler_data__ntasks; ++i) {
    }
  };
  {
    int _20;
    for (_20 = 0; _20 < 2; ++_20) {
      self->ss.tasks[_20].current_deadline = 0;
      self->ss.tasks[_20].current_proc = 2;
      self->ss.tasks[_20].status = Scheduler_data__Waiting;
    }
  };
  self->ss.current_date = -1;
}

void Scheduler__scheduler_step(int task_end[2],
                               Scheduler__scheduler_out* _out,
                               Scheduler__scheduler_mem* self) {
  Scheduler__start_inst_out Scheduler__start_inst_out_st;
  Scheduler__complete_out Scheduler__complete_out_st;
  Scheduler__check_deadline_out Scheduler__check_deadline_out_st;
  Scheduler__extract_proc_out Scheduler__extract_proc_out_st;
  Scheduler__rate_monotonic_mc_out Scheduler__rate_monotonic_mc_out_st;
  
  int v_22[2];
  int v_21[2];
  Scheduler_data__scheduler_state v;
  int new_date;
  Scheduler_data__task_status tmp1[2];
  Scheduler_data__task_status tmp2[2];
  Scheduler_data__task_status tmp3[2];
  Scheduler_data__task_status tmp4[2];
  {
    int i_4;
    for (i_4 = 0; i_4 < Scheduler_data__ntasks; ++i_4) {
      Scheduler__complete_step(self->ss.tasks[i_4], task_end[i_4],
                               &Scheduler__complete_out_st);
      tmp1[i_4] = Scheduler__complete_out_st.o;
    }
  };
  new_date = (self->ss.current_date+1);
  {
    int i_3;
    for (i_3 = 0; i_3 < Scheduler_data__ntasks; ++i_3) {
      v_22[i_3] = new_date;
    }
  };
  {
    int i_2;
    for (i_2 = 0; i_2 < Scheduler_data__ntasks; ++i_2) {
      v_21[i_2] = new_date;
    }
  };
  {
    int i_1;
    for (i_1 = 0; i_1 < Scheduler_data__ntasks; ++i_1) {
      Scheduler__check_deadline_step(v_21[i_1], tmp1[i_1], i_1,
                                     &Scheduler__check_deadline_out_st);
      tmp2[i_1] = Scheduler__check_deadline_out_st.tso;
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler_data__ntasks; ++i) {
      Scheduler__start_inst_step(v_22[i], tmp2[i], Scheduler_data__tasks[i],
                                 &Scheduler__start_inst_out_st);
      tmp3[i] = Scheduler__start_inst_out_st.tso;
    }
  };
  Scheduler__rate_monotonic_mc_step(tmp3,
                                    &Scheduler__rate_monotonic_mc_out_st);
  {
    int _17;
    for (_17 = 0; _17 < 2; ++_17) {
      tmp4[_17] = Scheduler__rate_monotonic_mc_out_st.tso[_17];
    }
  };
  Scheduler__extract_proc_step(tmp4, &Scheduler__extract_proc_out_st);
  {
    int _18;
    for (_18 = 0; _18 < 2; ++_18) {
      _out->task_run[_18] = Scheduler__extract_proc_out_st.o[_18];
    }
  };
  v.current_date = new_date;
  {
    int _19;
    for (_19 = 0; _19 < 2; ++_19) {
      v.tasks[_19] = tmp4[_19];
    }
  };
  self->ss = v;;
}

